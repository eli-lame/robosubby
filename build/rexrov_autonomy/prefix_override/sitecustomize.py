import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/osansubuntumachine/ros2_ws/install/rexrov_autonomy'
