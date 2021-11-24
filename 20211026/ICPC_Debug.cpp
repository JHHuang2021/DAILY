//参考谷歌C++代码风格
#include <iostream>
#include <unordered_map>
#include <set>
#include<functional>
#include<sstream>
#include <string>
#include <cstdio>

using namespace std;
int problem_count;//题目总数

struct Problem {//记录每道题的信息
    int submit_number = 0;//提交次数，正负有意义
    int total_submit = 0;//提交总数，仅正数
    int last_time_sub = 0;//最后一次提交时间
    int ac_time = 0;
    int tle_time = 0;
    int re_time = 0;
    int wa_time = 0;
    string last_status;//某一道题目的最后一次wa的时间，便于后期查询
    int first_ac_time = 0;
    int struggled_times = 0;//用来计算罚时
};
struct Team {
    string name;
    Problem parray[26];//保存各个题目的信息
    multiset<int, greater<>> ac_time_sorting;//每个队伍的每道题目有首次ac时间,用于比较排名
    //下面的信息用于状态查询，所有题目里某个status最后提交的题目和时间
    int last_submit_time = 0;
    int last_ac_time = 0;
    int last_tle_time = 0;
    int last_wa_time = 0;
    int last_re_time = 0;
    char last_ac = '\0';
    char last_re = '\0';
    char last_wa = '\0';
    char last_tle = '\0';
    char last_submit = '\0';
    int acnum = 0;
    int code;
};

bool operator<(const Team &lhs, const Team &rhs) {
    int l_penalty = 0, r_penalty = 0;
    for (int k = 0; k < problem_count; ++k) {
        l_penalty += (lhs.parray[k].first_ac_time + lhs.parray[k].struggled_times * 20);
        r_penalty += (rhs.parray[k].first_ac_time + rhs.parray[k].struggled_times * 20);
    }
    if (lhs.acnum == rhs.acnum) {
        if (l_penalty == r_penalty) {
            set<int, greater<>>::iterator itl, itr;
            for (itl = lhs.ac_time_sorting.begin(), itr = rhs.ac_time_sorting.begin();
                 *itl == *itr && itl != lhs.ac_time_sorting.end() && itr != rhs.ac_time_sorting.end();
                 ++itl, ++itr);
            if (itl == lhs.ac_time_sorting.end() && itr == rhs.ac_time_sorting.end())
                return lhs.name < rhs.name;
            else return *itl < *itr;
        } else return l_penalty < r_penalty;
    } else return lhs.acnum > rhs.acnum;
}

Team team_array[10010];

struct int_comp {
    bool operator()(const int &lhs, const int &rhs) const {
        return team_array[lhs] < team_array[rhs];
    }
};

unordered_map<string, Team> m;
set<int, int_comp> s;
set<int, int_comp> s_before;

//下面是重载比较条件

int main() {
    freopen("13.in", "r", stdin);
    freopen("test.out", "w", stdout);
    string stage_str1;
    cin >> stage_str1;
    int team_number = 0;
    while (1) {
        if (stage_str1 == "START") {
            //这里要做start相应的操作
            int duration;
            char ch[20];
            string start_information;
            stringstream info_deal;
            getline(cin, start_information);
            info_deal.clear();
            info_deal.str(start_information);
            info_deal >> ch >> duration >> ch >> problem_count;
            cout << "[Info]Competition starts." << endl;
            break;
        } else {
            //这里是add
            string name_add;
            cin >> name_add;
            if (m.count(name_add) == 0) {
                Team team_add{name_add};
                team_add.code = team_number;
                m[team_add.name] = team_add;
                team_array[team_number] = team_add;
                s.insert(team_number);//分别放到map,set,array
                team_number++;//此时正好是数量
                cout << "[Info]Add successfully." << endl;
            } else cout << "[Error]Add failed: duplicated team name." << endl;
        }
        cin >> stage_str1;
    }
    //这里是封榜数组的最初输入，字典顺序
    set<int, int_comp>::iterator initial_it;
    int i = 0;
    string sorting_array[team_number];//仍然用数组进行封榜，先用名字顺序
    for (initial_it = s.begin(); initial_it != s.end(); ++initial_it) {
        sorting_array[i] = team_array[*initial_it].name;
        ++i;
    }

    string stage_str2;
    cin >> stage_str2;
    bool whether_lock = false;
    bool flush_choice = false;
    while (1) {
        if (stage_str2 == "END") {
            //end的相应操作
            cout << "[Info]Competition ends." << endl;
            break;
        } else if (stage_str2 == "FREEZE") {
            if (whether_lock)cout << "[Error]Freeze failed: scoreboard has been frozen." << endl;
            else {
                s.clear();
                s_before.clear();
                for (int w = 0; w < team_number; ++w) {
                    team_array[w] = m[team_array[w].name];
                    s_before.insert(w);
                    s.insert(w);
                }
                cout << "[Info]Freeze scoreboard." << endl;
                whether_lock = true;
                flush_choice = true;
            }
        } else if (stage_str2 == "SCROLL") {
            if (whether_lock) {
                cout << "[Info]Scroll scoreboard." << endl;
                whether_lock = false;
                //下面输出封榜前的排名，这时不能直接从map set里面取，因为是要输出：前：
                set<int, int_comp>::iterator it_p;
                int j = 0;
                for (it_p = s_before.begin(); it_p != s_before.end(); ++it_p) {
                    Team print_team = team_array[*it_p];
                    int penalty = 0;
                    for (int k = 0; k < problem_count; ++k)
                        penalty += print_team.parray[k].struggled_times * 20 +
                                   print_team.parray[k].first_ac_time;
                    cout << print_team.name << " " << j + 1 << " " << print_team.acnum << " " << penalty;
                    for (int k = 0; k < problem_count; ++k) {
                        int submit_number_now = m[print_team.name].parray[k].submit_number;
                        int submit_number_before = print_team.parray[k].submit_number;
                        if (submit_number_before == 1)cout << " " << '+';
                        else if (submit_number_before > 1)cout << " +" << submit_number_before - 1;
                        else if (m[print_team.name].parray[k].total_submit ==
                                 print_team.parray[k].total_submit) {//没有被冻结
                            if (submit_number_before == 0)cout << " " << '.';
                            else if (submit_number_before < 0)cout << " " << submit_number_before;
                        } else {//题目被冻结了
                            int submit_times =
                                    m[print_team.name].parray[k].total_submit - print_team.parray[k].total_submit;
                            cout << " " << submit_number_before << '/' << submit_times;
                        }
                    }
                    ++j;
                    cout << endl;
                }
                set<int, int_comp>::reverse_iterator itt;
                while (!s_before.empty()) {
                    itt = s_before.rbegin();
                    Team replaced = team_array[*(s.rbegin())];
                    Team past = team_array[*itt];
                    Team present = m[past.name];
                    int q;
                    for (q = 0; q < problem_count; ++q) {
                        if (past.parray[q].submit_number != present.parray[q].submit_number) {
                            set<int, int_comp>::iterator it_f;
                            it_f = s.find(past.code);
                            Team after_me;
                            if ((++it_f) != s.end()) after_me = team_array[*(it_f)];
                            s.erase(past.code);
                            s_before.erase(past.code);
                            past.parray[q] = present.parray[q];
                            if (present.parray[q].submit_number > 0) {
                                past.acnum++;
                                past.ac_time_sorting.insert(present.parray[q].first_ac_time);
                            }
                            team_array[past.code] = past;
                            s.insert(past.code);
                            s_before.insert(past.code);
                            Team after_me_now;
                            set<int, int_comp>::iterator it_f2;
                            it_f2 = s.find(past.code);
                            if ((++it_f2) != s.end())after_me_now = team_array[*(it_f2)];

                            int penalty = 0;
                            for (int k = 0; k < problem_count; ++k)
                                penalty += past.parray[k].struggled_times * 20 +
                                           past.parray[k].first_ac_time;
                            if (it_f2 == s.end())
                                cout << past.name << " " << replaced.name << " " << past.acnum << " "
                                     << penalty
                                     << endl;
                            else if (after_me.name != after_me_now.name) {
                                cout << past.name << " " << after_me_now.name << " " << past.acnum << " "
                                     << penalty
                                     << endl;

                            }
                            break;
                        }
                    }
                    if (q == problem_count)s_before.erase(past.code);
                }
                s.clear();
                for (int h = 0; h < team_number; ++h) {
                    team_array[h] = m[team_array[h].name];
                    s.insert(h);
                }
                set<int, int_comp>::iterator it;
                int rank = 0;
                for (it = s.begin(); it != s.end(); ++it) {
                    rank++;
                    Team print_team1 = team_array[*it];
                    sorting_array[rank - 1] = print_team1.name;
                    int penalty1 = 0;
                    for (int k = 0; k < problem_count; ++k)
                        penalty1 += print_team1.parray[k].first_ac_time +
                                    print_team1.parray[k].struggled_times * 20;
                    cout << print_team1.name << " " << rank << " " << print_team1.acnum << " " << penalty1;
                    for (int h = 0; h < problem_count; ++h) {
                        if (print_team1.parray[h].submit_number == 1)cout << " " << '+';
                        else if (print_team1.parray[h].submit_number == 0)cout << " " << '.';
                        else if (print_team1.parray[h].submit_number > 1)
                            cout << " +" << print_team1.parray[h].submit_number - 1;
                        else if (print_team1.parray[h].submit_number < 0)
                            cout << " " << print_team1.parray[h].submit_number;
                    }
                    cout << endl;
                }

            } else cout << "[Error]Scroll failed: scoreboard has not been frozen." << endl;
        } else if (stage_str2 == "START") {
            string invalid;
            getline(cin, invalid, '\n');
            cout << "[Error]Start failed: competition has started." << endl;
        } else if (stage_str2 == "ADDTEAM") {
            string invalid;
            getline(cin, invalid, '\n');
            cout << "[Error]Add failed: competition has started." << endl;
        } else if (stage_str2 == "SUBMIT") {
            stringstream info_deal;
            string submit_info;
            getline(cin, submit_info);
            info_deal.clear();
            info_deal.str(submit_info);
            char problem_name;
            string team_name, status;
            char ch[25];
            int time;
            info_deal >> problem_name >> ch >> team_name >> ch >> status >> ch >> time;
            Team team_submit = m[team_name];
            m.erase(team_name);
            team_submit.parray[problem_name - 'A'].last_time_sub = time;
            int a = team_submit.parray[problem_name - 'A'].submit_number;
            if (status == "Accepted") {
                if (team_submit.parray[problem_name - 'A'].ac_time == 0) {
                    team_submit.acnum++;
                    team_submit.ac_time_sorting.insert(time);
                    team_submit.parray[problem_name - 'A'].first_ac_time = time;
                    team_submit.parray[problem_name - 'A'].struggled_times = abs(
                            team_submit.parray[problem_name - 'A'].submit_number);
                }
                if (team_submit.parray[problem_name - 'A'].submit_number <= 0)
                    team_submit.parray[problem_name - 'A'].submit_number = abs(a) + 1;
                team_submit.parray[problem_name - 'A'].ac_time = time;
                team_submit.last_ac_time = time;
                team_submit.last_ac = problem_name;
                team_submit.last_submit_time = time;
                team_submit.last_submit = problem_name;
                team_submit.parray[problem_name - 'A'].last_status = "Accepted";
                team_submit.parray[problem_name - 'A'].total_submit++;
            } else if (status == "Wrong_Answer") {
                team_submit.parray[problem_name - 'A'].wa_time = time;
                if (team_submit.parray[problem_name - 'A'].submit_number <= 0)
                    --(team_submit.parray[problem_name - 'A'].submit_number);
                team_submit.last_wa_time = time;
                team_submit.last_wa = problem_name;
                team_submit.last_submit_time = time;
                team_submit.last_submit = problem_name;
                team_submit.parray[problem_name - 'A'].last_status = "Wrong_Answer";
                team_submit.parray[problem_name - 'A'].total_submit++;

            } else if (status == "Runtime_Error") {
                team_submit.parray[problem_name - 'A'].re_time = time;
                if (team_submit.parray[problem_name - 'A'].submit_number <= 0)
                    --(team_submit.parray[problem_name - 'A'].submit_number);
                team_submit.last_re_time = time;
                team_submit.last_re = problem_name;
                team_submit.last_submit_time = time;
                team_submit.last_submit = problem_name;
                team_submit.parray[problem_name - 'A'].last_status = "Runtime_Error";
                team_submit.parray[problem_name - 'A'].total_submit++;

            } else if (status == "Time_Limit_Exceed") {
                team_submit.parray[problem_name - 'A'].tle_time = time;
                if (team_submit.parray[problem_name - 'A'].submit_number <= 0)
                    --(team_submit.parray[problem_name - 'A'].submit_number);
                team_submit.last_tle_time = time;
                team_submit.last_tle = problem_name;
                team_submit.last_submit_time = time;
                team_submit.last_submit = problem_name;
                team_submit.parray[problem_name - 'A'].last_status = "Time_Limit_Exceed";
                team_submit.parray[problem_name - 'A'].total_submit++;

            }
            m[team_name] = team_submit;
        } else if (stage_str2 == "FLUSH") {
            cout << "[Info]Flush scoreboard." << endl;
            //上面是用string sorting——array储存了排名
            if (!whether_lock) {//此时set里面的还没有更新其实是要更新team array
                s.clear();
                for (int h = 0; h < team_number; ++h) {
                    team_array[h] = m[team_array[h].name];
                    s.insert(h);
                }
                set<int, int_comp>::iterator it;
                int rank_ = 0;
                for (it = s.begin(); it != s.end(); ++it) {
                    sorting_array[rank_] = team_array[(*it)].name;
                    ++rank_;
                }//query 的时候就由array里面询问排名，从结构体里找具体信息
            } else if (flush_choice) {
                set<int, int_comp>::iterator set_it;
                int j = 0;
                for (set_it = s_before.begin(); set_it != s_before.end(); ++set_it) {
                    sorting_array[j] = team_array[*set_it].name;
                    ++j;
                    flush_choice = false;
                }
            }
        } else if (stage_str2 == "QUERY_RANKING") {
            string team_name;
            cin >> team_name;
            int k;
            for (k = 0; k < team_number; ++k) {
                if (sorting_array[k] == team_name) {
                    cout << "[Info]Complete query ranking." << endl;
                    if (whether_lock)
                        cout
                                << "[Warning]Scoreboard is frozen. The ranking may be inaccurate until it were scrolled. "
                                << endl;
                    cout << team_name << " NOW AT RANKING " << k + 1 << endl;
                    k = -1;
                    break;
                }
            }
            if (k >= 0)cout << "[Error]Query ranking failed: cannot find the team." << endl;
        } else if (stage_str2 == "QUERY_SUBMISSION") {
            string invalid_info, team_name;
            for (int i = 1; i <= 6; i++)
                cin >> invalid_info;
//            cin >> team_name;
//            if (m.count(team_name) == 1) {
//                cout << "[Info]Complete query submission." << endl;
//                Team query_team = m[team_name];
//                getline(cin, invalid_info, '=');
//                string problem_query;
//                cin >> problem_query;
//                getline(cin, invalid_info, '=');
//                string status_query;
//                cin >> status_query;
//                if (problem_query == "ALL" && status_query == "ALL") {
//                    problem_query = query_team.last_submit;
//                    status_query = query_team.parray[problem_query[0] - 'A'].last_status;
//                    if (query_team.last_submit_time == 0)cout << "Cannot find any submission." << endl;
//                    else
//                        cout << team_name << " " << problem_query << " " << status_query << " "
//                             << query_team.last_submit_time << endl;
//                } else if (problem_query == "ALL") {
//                    if (status_query == "Accepted") {
//                        problem_query = query_team.last_ac;
//                        if (query_team.last_ac_time == 0)cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.last_ac_time << endl;
//                    } else if (status_query == "Wrong_Answer") {
//                        problem_query = query_team.last_wa;
//                        if (query_team.last_wa_time == 0)cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.last_wa_time << endl;
//                    } else if (status_query == "Runtime_Error") {
//                        problem_query = query_team.last_re;
//                        if (query_team.last_re_time == 0)cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.last_re_time << endl;
//                    } else if (status_query == "Time_Limit_Exceed") {
//                        problem_query = query_team.last_tle;
//                        if (query_team.last_tle_time == 0)cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.last_tle_time << endl;
//                    }
//                } else if (status_query == "ALL") {
//                    status_query = query_team.parray[problem_query[0] - 'A'].last_status;
//                    if (query_team.parray[problem_query[0] - 'A'].last_time_sub == 0)
//                        cout << "Cannot find any submission." << endl;
//                    else
//                        cout << team_name << " " << problem_query << " " << status_query << " "
//                             << query_team.parray[problem_query[0] - 'A'].last_time_sub << endl;
//
//                } else {
//                    if (status_query == "Accepted") {
//                        if (query_team.parray[problem_query[0] - 'A'].ac_time == 0)
//                            cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.parray[problem_query[0] - 'A'].ac_time << endl;
//                    } else if (status_query == "Wrong_Answer") {
//                        if (query_team.parray[problem_query[0] - 'A'].wa_time == 0)
//                            cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.parray[problem_query[0] - 'A'].wa_time << endl;
//                    } else if (status_query == "Runtime_Error") {
//                        if (query_team.parray[problem_query[0] - 'A'].re_time == 0)
//                            cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.parray[problem_query[0] - 'A'].re_time << endl;
//                    } else if (status_query == "Time_Limit_Exceed") {
//                        if (query_team.parray[problem_query[0] - 'A'].tle_time == 0)
//                            cout << "Cannot find any submission." << endl;
//                        else
//                            cout << team_name << " " << problem_query << " " << status_query << " "
//                                 << query_team.parray[problem_query[0] - 'A'].tle_time << endl;
//                    }
//                }
//            } else cout << "[Error]Query submission failed: cannot find the team." << endl;
//        }
//        cin >> stage_str2;
        }
    }
    return 0;
}