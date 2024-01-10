..
    Copyright 2023 MicroEJ Corp. All rights reserved.
    Use of this source code is governed by a BSD-style license that can be found with this software..

.. |BOARD_NAME| replace:: NUCLEO-F429ZI
.. |VEEPORT_VER| replace:: 1.0.0
.. |VEEPORT| replace:: VEE Port
.. |MANUFACTURER| replace:: STMicroelectronics
.. |MICROEJ_ARCHITECTURE_VERSION| replace:: 8.0.0

=======================================================
|VEEPORT| Release Notes for |MANUFACTURER| |BOARD_NAME|
=======================================================

Description
===========

This is the release notes of the |VEEPORT| for |BOARD_NAME|.

Versions
========

|VEEPORT|
---------

|VEEPORT_VER|

Dependencies
------------

This |VEEPORT| contains the following dependencies:

.. list-table::
   :header-rows: 1
   
   * - Dependency Name
     - Version
   * - Architecture (flopi4I35)
     - |MICROEJ_ARCHITECTURE_VERSION|

Please refer to the |VEEPORT| `module description file <./stm32f429zi_nucleo_freertos-configuration/module.ivy>`_ 
for more details.

Board Support Package
---------------------

- BSP provider and name:  (``STM32Cube FW_F4``)
- BSP version: v1.28.0

Please refer to the |MANUFACTURER| (``STM32Cube FW_F4``) git repository
available `here
<https://github.com/STMicroelectronics/STM32CubeF4.git>`__.

Third Party Software
--------------------

Third party software used in BSP can be found `here
<https://github.com/STMicroelectronics/STM32CubeF4/tree/master/Middlewares/Third_Party/FreeRTOS/Source>`__. Here
is a list of the most important ones:

.. list-table::
   :widths: 3 3 3

   * - RTOS 
     - FreeRTOS
     - 10.3.1
 

Features
========

The |VEEPORT| features only the core features.



Known Issues/Limitations
========================

Known issues:



Limitations:



|VEEPORT| Memory Layout
=======================

Memory Sections
---------------

Each memory section is described in the stm32f429xx_flash.icf linker file 
available in the folder stm32f429zi_nucleo_freertos-bsp\\projects\\microej\\EWARM\\.


Memory Layout
-------------

.. list-table::
   :header-rows: 1
   
   * - Section Content
     - Section Source
     - Section Destination
     - Memory Type
   * - MicroEJ Application static
     - ``.bss.soar``
     - ``.bss``
     - internal SRAM
   * - MicroEJ Application threads stack blocks 
     - ``.bss.vm.stacks.java``
     - ``.ext_ram.bss``
     - internal SRAM
   * - MicroEJ Core Engine internal heap 
     - ``ICETEA_HEAP``
     - ``.ext_ram.bss``
     - internal SRAM
   * - MicroEJ Application heap 
     - ``_java_heap``
     - ``.ext_ram.bss``
     - internal SRAM
   * - MicroEJ Application Immortal Heap 
     - ``_java_immortals``
     - ``.ext_ram.bss``
     - internal SRAM
   * - MicroEJ Application resources 
     - ``.rodata.resources``
     - ``.rodata``
     - internal FLASH
   * - MicroEJ System Applications code and resources 
     - ``.rodata.soar.features``
     - ``.rodata``
     - internal FLASH
   * - MicroEJ System Application statics 
     - ``.bss.features.installed``
     - ``.ext_ram.bss``
     - ``-``
   * - MicroEJ Shielded Plug data 
     - ``.shieldedplug``
     - ``.rodata``
     - ``-``
   * - MicroEJ Application and Library code 
     - ``.text.soar``
     - ``.rodata``
     - internal FLASH
   * - MicroUI frame buffer
     - ``-``
     - ``.ext_ram.bss``
     - ``-``


Please also refer to the MicroEJ docs website page available `here
<https://docs.microej.com/en/latest/VEEPortingGuide/coreEngine.html#link>`__
for more details.

