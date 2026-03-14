#pragma once

#include "bot/bot.hpp"
#include "bot/pid.hpp"
#include "location.hpp"
#include "bot/types.hpp"

namespace bot {

class Drivetrain {
    public:
        Drivetrain(
            vex::motor_group& left_dt,
            vex::motor_group& right_dt,
            vex::inertial& imu
        );
        volatile bool _arm_assist = false;
        void set_arm_assist(bool value);
        volatile double _arm_assist_heading = 0.0;
        void set_arm_assist_heading(double heading);
        inline double arm_assist_heading() { return _arm_assist_heading; }
        inline bool arm_assist() { return _arm_assist; }
        void start_arm_assist();
        void stop_arm_assist();



        void arm_left();
        void arm_right();

        void tank_drive(double left_speed, double right_speed);
        void arcade_drive(double fwd, double turn);
        void stop();
        void brake();
        void coast();
        void hold();

        void drive_for(double distance, double timeout, double speed_limit, double target_heading);
        void drive(double distance, double timeout, double speed_limit, double target_heading);
        void turn_to_heading(double heading, double timeout, double speed_limit);
        void drive_arc(double radius, double angle, double timeout, double speed_limit, double lookahead);
        void drive_dist(double target_distance, double timeout, double speed_limit, double target_heading, double distance_tolerance, vex::distance& distance_sensor);
        void drive_dist_front(double target_distance, double timeout, double speed_limit, double target_heading, double distance_tolerance, vex::distance& distance_sensor);
        void match_load(int times);
        void drive_to(std::vector<Waypoint> waypoints, double speed_limit);
    private:
        vex::motor_group& _left_dt;
        vex::motor_group& _right_dt;
        vex::inertial& _imu;
        double _wheel_diameter;
        double _track_width;
        double _gear_ratio;
        double _max_voltage;
        double _max_accel;
        PID _drive_pid;
        PID _heading_pid;
        PID _turn_pid;
        PID _left_arc_pid;
        PID _right_arc_pid;
        PID _heading_pidf;
        PID _distance_pidf;
        PID _arm_assist_pid;
};

}