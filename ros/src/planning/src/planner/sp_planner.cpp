#include "planning/planner/sp_planner.h"

SpPlanner::SpPlanner(YAML::Node yaml_conf)
:Planner(yaml_conf){
sampler = new SamplerPoint(yaml_conf["SamplerPoint_conf"]); 
dpgraph = new DpRoadGraph(yaml_conf);  
stgraph = new DpStGraph(yaml_conf);
}


Car_State_SL SpPlanner::get_start_point(const car_msgs::trajectory_point car_status,const Car_State_SL& status_sl,car_msgs::trajectory& trajectory_now){
    static bool replanning_flag = 0;
    /*********************************************/
    //重新从车的当前位置开始规划的条件
    //1.预测的时间为0，设定成这样
    //2.上次轨迹丢失
    //3.车体偏离预设轨迹较远
    //  if(conf.keep_t==0||trajectory_now.total_path_length<5||
    //         TrajectoryStitcher::replanningTrajectory(car_status, trajectory_now, conf.available_l)){
        //重置标志位
        replanning_flag = 1;
        //设置起点为车的当前坐标
        Car_State_SL start_sl = status_sl;
        start_sl.index = 0;
        return start_sl;
    //  }
    //  else{
    //     int start_index=0;
    //     while(start_index<trajectory_now.total_path_length-1&&status_sl.s-trajectory_now.trajectory_path[start_index].s>0) start_index++;
    //     float T0 = trajectory_now.trajectory_path[start_index].relative_time;
    //     VectorXf T(1);
        
    //     //第一次运行时间是没有偏差的
    //     if(replanning_flag){
    //         T<<(T0 + conf.keep_t);
    //         replanning_flag = 0;
    //     }else
    //         //预测一秒后的，本来这里要加上1，但由于后面相对时间是从0开始算的，已经加了1，
    //         T<<T0;
    //     MatrixXf S_out;
    //     Fitting::cal_point_quartic4(QP4,T,S_out);
    //     VectorXf S(1);
    //     S(0) = S_out(0,0) - car_last_sl.s;
    //     MatrixXf L_out;
    //     Fitting::cal_point_quintic5(QP5 ,S,L_out);
    //     int end_index = start_index+5;
    //     while(end_index<trajectory_now.total_path_length-1&&S_out(0,0)-trajectory_now.trajectory_path[end_index].s>0) end_index++;
    //     int len1 = end_index - start_index;
    //     for(int i=0;i<len1;i++){
    //         trajectory_now.trajectory_path[i] = trajectory_now.trajectory_path[i+start_index];
    //         trajectory_now.trajectory_path[i].relative_time -=T0;
    //         trajectory_now.trajectory_path[i].header.seq = i+1;
    //     }
    //     //设置起点为end_index当前坐标
    //     Car_State_SL start_sl;
    //     // start_sl.index = status_sl.index;
    //     // Coordinate_converter::POS_to_SL(refrence_Trajectory,trajectory_now.trajectory_path[end_index],start_sl);
    //     start_sl.s = S_out(0,0);
    //     start_sl.sv = S_out(0,1);
    //     start_sl.sa = S_out(0,2);
    //     start_sl.l = L_out(0,0);
    //     start_sl.dl = L_out(0,1);
    //     start_sl.ddl = L_out(0,2);
    //     start_sl.index = len1;
    //     // cout<<"QP4"<<endl;
    //     // cout<<QP4<<endl;
    //     // cout<<"S_out"<<endl;
    //     // cout<<S_out<<endl;
    //     // cout<<"car_S:"<<status_sl.s<<"  1s_car_S:"<<S_out(0,0)<<endl;
    //     // cout<<"start_pos:"<<start_index<<"  end_pos:"<<end_index<<endl;
    //     return start_sl;
    //  }
}

 void SpPlanner::get_current_line(const car_msgs::trajectory_point car_status,const Car_State_SL& status_sl,
                                         const Spline_Out* refrenceline_Sp, car_msgs::trajectory& trajectory_now){
    /*****************获得采样的起始点***********************/
    Car_State_SL start_sl = get_start_point(car_status,status_sl,trajectory_now);

    double planning_s = 5;
    double planning_t = 5;
    double planning_l = 5;
    sampler->reset(start_sl);
    //L采样
    vector<Car_State_SL> SamplerPointsL;
    sampler->getpointsL(planning_s, planning_t, SamplerPointsL);
    RoadGraphNode min_road_Node;
    dpgraph->reset(start_sl, 1);//只采一行
    dpgraph->process(SamplerPointsL, &min_road_Node);
    QP5 = min_road_Node.minQP5;
    planning_l = min_road_Node.l;
    //T采样
    vector<Car_State_SL> SamplerPointsT;
    sampler->getpointsT(planning_l, planning_s, SamplerPointsT);
    StGraphNode min_st_Node;
    stgraph->reset(start_sl,1);
    stgraph->process(SamplerPointsS, &min_st_Node);
    QP4 = min_st_Node.minQP4;



    for(int i=start_sl.index;i<trajectory_now.total_path_length;i++)
        trajectory_now.trajectory_path[i].relative_time +=conf.keep_t;
    /************debug 1***********/
    // for(int i=0;i<len;i++)
    // cout<<
    // trajectory_now.trajectory_path[start_index+i].header.seq<<","<<
    // trajectory_now.trajectory_path[start_index+i].x<<","<<
    // trajectory_now.trajectory_path[start_index+i].y<<","<<
    // trajectory_now.trajectory_path[start_index+i].theta<<","<<
    // trajectory_now.trajectory_path[start_index+i].kappa<<endl;
    /************debug 2***********/
    // for(int i=0;i<trajectory_now.total_path_length;i++)
    // cout<<
    // trajectory_now.trajectory_path[i].header.seq<<"."<<
    // " s:"<<trajectory_now.trajectory_path[i].s<<
    // " t:"<<trajectory_now.trajectory_path[i].relative_time<<
    // " x:"<<trajectory_now.trajectory_path[i].x<<
    // " y:"<<trajectory_now.trajectory_path[i].y<<","<<
    // " theta:"<<trajectory_now.trajectory_path[i].theta<<","<<
    // " kappa:"<<trajectory_now.trajectory_path[i].kappa<<endl;
    // return;
 }

void SpPlanner::process(const car_msgs::trajectory_point car_status,const Car_State_SL& status_sl,
                                 const Spline_Out* refrenceline_Sp, car_msgs::trajectory& trajectory_now){
    static int count = 0;
    count++;
    get_current_line(car_status, status_sl, refrenceline_Sp, trajectory_now);
    //添加header
    trajectory_now.header.seq = count;
    //保存车体参数
    car_last_sl = status_sl;
}

