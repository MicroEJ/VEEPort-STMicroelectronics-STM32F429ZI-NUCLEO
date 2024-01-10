.. 
    Copyright 2023 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software.

.. |BOARD_NAME| replace:: NUCLEO-F429ZI
.. |VEEPORT| replace:: VEE Port
.. |RTOS| replace:: FreeRTOS
.. |BSP_FULL_NAME| replace:: STM32CubeF4 MCU Firmware Package
.. |BSP_SHORT_NAME| replace:: STM32CubeF4

.. _README: ./../../../README.rst

================
|BOARD_NAME| BSP
================

This project contains the BSP sources of the |VEEPORT| for the
|BOARD_NAME|. The BSP project is based on |BSP_FULL_NAME| (|BSP_SHORT_NAME|).

This document does not describe how to setup the |VEEPORT|. Please
refer to the `README`_ for that.

Build & Run Scripts
---------------------

In the directory ``Project/microej/scripts/`` are scripts that can be
used to build and flash the BSP.  The ``.bat`` and ``.sh`` scripts are
meant to run in a Windows and Linux environment respectively.

- The ``build*`` scripts are used to compile and link the BSP with a
  MicroEJ Application to produce a MicroEJ Firmware
  (``application.out``) that can be flashed on a device.

  The ``build*`` scripts work out of the box, assuming the toolchain is
  installed in the default path.

- The ``run*`` scripts are used to flash a MicroEJ Firmware
  (``application.out``) on a device.


See the comments for each variables in the scripts for a detailed
explanation.>

The environment variables can be defined globally by the user or in
the ``set_local_env*`` scripts.  When the ``.bat``  scripts
are executed, the ``set_local_env.bat``  script
is executed if it exists.  Create and configure these files to
customize the environment locally.  Template files are provided as
example, see ``set_local_env.bat.tpl`` and ``set_local_env.sh.tpl``.


Flash the Board
---------------

The ``run*`` scripts can also be used to flash the device with the
MicroEJ Firmware.


Debugging with |BOARD_NAME|
---------------------------

A debug session can be started using IAR IDE. Once the IAR IDE is open with the workspace ``stm32f429zi_nucleo_freertos-bsp\projects\microej\EWARM\Project.eww``,

- Right click on the project and select ``Options...``.
- Then go to the ``C/C++ Compiler`` tab and set the ``Optimizations > Level`` to ``None``.
- After that, rebuild the firmware and click on ``Project > Download and Debug``.

Dependencies
------------

The following dependencies are included as part of the BSP:

- name="bsp-microej-main" rev="2.0.0"
- name="bsp-generic" rev="1.1.0"
- name="mjvm-freertos" rev="1.1.0"
