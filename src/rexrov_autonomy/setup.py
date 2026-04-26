from setuptools import setup

package_name = 'rexrov_autonomy'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='osansubuntumachine',
    maintainer_email='osansubuntumachine@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
		'autonomous_node = rexrov_autonomy.autonomous_node:main',
		'near_gate_detector = rexrov_autonomy.autonomous_node:main',
		'autonomous_reset = rexrov_autonomy.autonomous_reset:main',
		'autopath = rexrov_autonomy.autopath:main',
        'perception_node = rexrov_autonomy.perception_node:main',
        'bt_gate = rexrov_autonomy.bt_gate:main',
        ],
    },
)
