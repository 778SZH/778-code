#!/bin/bash
# ROS2 Humble 环境自检：不是只看装没装，而是真的跑两个节点通信
# 用法：wsl -d Ubuntu-22.04 -- bash /mnt/d/workspace/cpp-stm32-notes/ros2/verify_env.sh
source /opt/ros/humble/setup.bash

echo "===== 1) 基础信息 ====="
echo "ROS_DISTRO = $ROS_DISTRO"
echo "系统       = $(lsb_release -ds)"
echo "g++        = $(g++ --version | head -1)"
echo "colcon     = $(command -v colcon)"
echo "包总数     = $(ros2 pkg list | wc -l)"

echo
echo "===== 2) 两个节点通信（talker -> listener） ====="
timeout 12 ros2 run demo_nodes_cpp talker > /tmp/talk.log 2>&1 &
sleep 3
timeout 8 ros2 run demo_nodes_cpp listener > /tmp/listen.log 2>&1
wait
echo "--- talker ---"
head -3 /tmp/talk.log
echo "--- listener ---"
head -3 /tmp/listen.log

echo
echo "===== 3) 自己发布 / 订阅一个话题 ====="
(timeout 10 ros2 topic pub -r 5 /test_topic std_msgs/msg/String "{data: hello_from_songzihao}" > /tmp/pub.log 2>&1 &)
sleep 2
timeout 6 ros2 topic echo /test_topic std_msgs/msg/String --once

echo
echo "===== 4) turtlesim 能不能起来 ====="
(timeout 8 ros2 run turtlesim turtlesim_node > /tmp/turtle.log 2>&1 &)
sleep 5
ros2 node list
head -3 /tmp/turtle.log
echo "===== 自检结束 ====="
