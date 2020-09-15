# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\e.ivanov\Documents\GitHub\generic\Manchester encoder-decoder.cydsn\Manchester encoder-decoder.cyprj
# Date: Mon, 14 Sep 2020 12:19:03 GMT
#set_units -time ns
create_clock -name {Clock_2(routed)} -period 27.777777777777775 -waveform {0 13.8888888888889} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {CyXTAL} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_5} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_10} -source [get_pins {ClockBlock/clk_sync}] -edges {1 73 145} [list [get_pins {ClockBlock/dclk_glb_2}]]

set_false_path -from [get_pins {__ONE__/q}]
set_false_path -from [get_pins {__ZERO__/q}]

# Component constraints for C:\Users\e.ivanov\Documents\GitHub\generic\Manchester encoder-decoder.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\e.ivanov\Documents\GitHub\generic\Manchester encoder-decoder.cydsn\Manchester encoder-decoder.cyprj
# Date: Mon, 14 Sep 2020 12:18:56 GMT