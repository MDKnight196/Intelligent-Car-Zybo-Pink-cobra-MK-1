connect -url tcp:127.0.0.1:3121
source C:/Users/ulab/Desktop/EdisonTechnologyFinalVehicle/EdisonTechnologyFinalVehicle.sdk/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -filter {name =~"APU" && jtag_cable_name =~ "Digilent Zybo 210279786236A"} -index 0
loadhw C:/Users/ulab/Desktop/EdisonTechnologyFinalVehicle/EdisonTechnologyFinalVehicle.sdk/design_1_wrapper_hw_platform_0/system.hdf
targets -set -filter {name =~"APU" && jtag_cable_name =~ "Digilent Zybo 210279786236A"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279786236A"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279786236A"} -index 0
dow C:/Users/ulab/Desktop/EdisonTechnologyFinalVehicle/EdisonTechnologyFinalVehicle.sdk/PinkCobra_mk1/Debug/PinkCobra_mk1.elf
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279786236A"} -index 0
con
