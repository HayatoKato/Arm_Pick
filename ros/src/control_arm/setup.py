from setuptools import setup

package_name = 'control_arm'

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
    maintainer='hkato',
    maintainer_email='hkato@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'control_arm_node = control_arm.control_arm_node:main',
            'control_arm_node_test = control_arm.control_arm_node_test:main',
        ],
    },
)
