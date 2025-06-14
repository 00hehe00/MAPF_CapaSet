/*******************************************
* Author: Shuai Zhou.
* Organization: Raplab
 * All Rights Reserved.
 *******************************************/
#ifndef CPPRAPLAB_MAPFAA_LSRP_HPP
#define CPPRAPLAB_MAPFAA_LSRP_HPP

#include "mapfaa_util.hpp"
#include <vector>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <random>
#include <optional>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <iostream>
#include <string>
#include <cassert>
#include <iosfwd>
#include <iosfwd>
#include <vector>
#include <vector>


namespace raplab {
    


    struct State {
    public:
        State();

        State(long parent_v, long v, double parent_time, double time);

        bool operator==(const State &other) const;

        std::size_t hash() const;

        std::tuple<long, long, double, double> get_tuple() const;

        double get_endT() const;

        double get_startT() const;

       long get_v() const;

        long get_p() const;


    private:
        long p;
        long v;
        double startT;
        double endT;


    };

    struct StateHash {
        std::size_t operator()(const State& s) const {
            return s.hash();
        }
    };


    struct Agent {
    public:
        Agent();

        Agent(int id, long start, long goal);

        void set_init_priority(double priority);

        void set_priority(double pri);

        int get_id() const;

        State* get_curr() const;

        bool operator==(const Agent &other) const;

        bool is_at_goal() const;

        double get_init_priority() const;

        double get_priority() const;

        void set_curr(State* &curr);

        void set_at_goal(bool at_goal);

        long get_goal() const;

        State* curr;

    private:
        int id;
        double priority;
        double init_pri;
        long goal;
        bool at_goal;


    };

    class Lsrp : public MAPFAAPlanner {
    public:

        Lsrp();

        /**
        *
        */
        virtual ~Lsrp();


        virtual bool reach_Goal() const;

        virtual double get_tmin2() const;

        virtual std::vector<Agent *> extract_Agents(double t);

        virtual std::vector<State*> get_rawSnext(std::vector<State*> S_from,
                                                             const std::vector<Agent *> &curr_agents, double t) const;

        virtual void update_Priority();

        virtual double get_duration(const Agent &agent, long v1 = 0, long v2 = 0) const;

        virtual bool
        check_Occupied(const Agent &agent, const long &v, const std::vector<State*> &Sto,
                       const std::vector<long> &constrain_list, bool in_pibt) const;

        virtual bool check_potential_deadlock(const long &v, const Agent &ag,
                                              const std::vector<State*> &Sfrom,
                                              const std::vector<State*> &Sto) const;

        virtual double get_makespan();

        virtual double get_Soc();


        void extract_policy();

        int _lsrp();

        virtual double re_soc() ;

        virtual double re_makespan() ;

        virtual CostVec GetPlanCost(long nid=-1) override ;

        virtual void Setduration(std::vector<double> duration) {_duration = duration;}

        virtual void Set_minduration();

        virtual TimePathSet GetPlan(long nid=-1) override ;

        virtual double GetRuntime(long nid = -1) {return _runtime;}

        virtual int Solve(std::vector<long>& starts, std::vector<long>& goals, double time_limit, double eps) override ;

        virtual std::unordered_map<std::string, double> GetStats() override ;

        virtual Agent*
        push_required(const std::vector<Agent *> &curr_agents, const Agent &agent, const long &v,
                      const std::vector<State*> &Sfrom, const std::vector<State*> &Sto) const;

        virtual double _asy_push(Agent &agent, std::vector<State*> &Sto,
                             const std::vector<State*> &Sfrom, const std::vector<Agent *> &curr_agents,
                             double tmin2, double curr_t,std::vector<long> &constrain_list, bool bp);


        virtual Agent* swap_required_possible(const std::vector<Agent *> &curr_agents,const Agent &agent,
                                              const std::vector<State*> &Sfrom,std::vector<State*> &Sto,
                                              std::vector<long> &C);

        virtual bool swap_required(const Agent &pusher,const Agent &puller,const std::vector<State*> &Sfrom,
                                   std::vector<State*> &Sto,long v_pusher_init,long v_puller_init);

        virtual bool swap_possible(const std::vector<State*> &Sfrom,std::vector<State*> &Sto,
                                   long v_pusher_init,long v_puller_init);

        virtual Agent* Check_occupied_forSwap(const std::vector<Agent*>& curr_agents,
                                              const long& u,
                                              const std::vector<State*>& Sfrom,
                                              const std::vector<State*>& Sto, bool curr_A_required);

        virtual double _asy_push_swap(Agent &agent, std::vector<State*> &Sto,
                             const std::vector<State*> &Sfrom, const std::vector<Agent *> &curr_agents,
                             double tmin2, double curr_t,std::vector<long> &constrain_list, bool bp);


        virtual bool highest_pri_agents(Agent &agent);


        void set_swap(bool swap) {_swap = swap;}

        void set_edge_cost(std::unordered_map<int,std::unordered_map<int,double>> edge_cost) {this->edge_cost = edge_cost;}

        int edge_hash (long a, long b) const;

        std::vector<std::vector<std::tuple<long, long, double, double>>>* get_all_paths() {return &_all_paths;}


    private:

        void insert_policy(const std::vector<std::tuple<Agent, State*>> &agent_state_list,
                           std::unordered_map<double, std::vector<State*>> &new_policy) const;

        void
        merge_policy(const std::unordered_map<double, std::vector<State*>> &new_policy, double curr_t);

        void update(const std::vector<Agent *> &curr_agents, std::vector<State*> Sto);

        std::vector<std::unordered_map<long,double>> generate_distable();

        std::unordered_map<long,double> generate_single_dis_table(int agent);

        double get_h(const Agent &agent, const long &coord);

        void set_agents();

        std::vector<std::vector<State*>> set_initPolicy();

        State generate_state(const long &v, const Agent &agent,
                             const std::vector<State*> &Sfrom,
                             double* tmin2) const;

        std::vector<long> _Sinit;
        std::vector<long> _Send;
        std::vector<double> _duration;
        std::unordered_map<int,std::unordered_map<int,double>> edge_cost; // use when specified edge cost
        std::vector<std::unordered_map<long,double>> _dis_table;
        std::priority_queue<double, std::vector<double>, std::greater<double>> _T;
        std::unordered_set<double> _T_set;
        std::unordered_map<double, std::vector<State*>> _cache;
        std::vector<Agent*> _agents;
        mutable std::vector<std::vector<State*>> _S_T;
        double _min_duration;
        double _soc;
        double _makespan;
        double _time_limit;
        double _runtime;
        std::mt19937 _rng = std::mt19937(0);
        bool _swap;
        std::unordered_map<std::string, double> _stats;
        TimePathSet _paths;
        std::vector<std::vector<std::tuple<long, long, double, double>>> _all_paths;
    };
}

#endif //CPPRAPLAB_MAPFAA_LSRP_HPP
