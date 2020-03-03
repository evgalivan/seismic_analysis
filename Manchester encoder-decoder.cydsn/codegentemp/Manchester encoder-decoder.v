// ======================================================================
// Manchester encoder-decoder.v generated from TopDesign.cysch
// 03/03/2020 at 16:39
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC5LP 2
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 3
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_TMA4 4
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 5
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC6ABLE2 6
`define CYDEV_CHIP_REV_PSOC6ABLE2_ES 17
`define CYDEV_CHIP_REV_PSOC6ABLE2_PRODUCTION 33
`define CYDEV_CHIP_REV_PSOC6ABLE2_NO_UDB 33
`define CYDEV_CHIP_DIE_VOLANS 7
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 8
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 9
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 10
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 11
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4O 7
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 8
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 9
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 10
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 11
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 12
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 13
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 14
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 15
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 16
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 17
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 18
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 19
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 20
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 21
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 22
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 23
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 24
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 28
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 29
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_vref_v1_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70\cy_vref_v1_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70\cy_vref_v1_70.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Comp_v2_0(Hysteresis=0, Pd_Override=0, Polarity=0, PSOC5A=false, Speed=1, Sync=1, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Comp_v2_0, CY_CONFIG_TITLE=Comp_2, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Comp_2, CY_INSTANCE_SHORT_NAME=Comp_2, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Comp_2, )
module Comp_v2_0_0 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_1;


    assign Net_9 = ~Net_1;



endmodule

// Comp_v2_0(Hysteresis=0, Pd_Override=0, Polarity=0, PSOC5A=false, Speed=1, Sync=1, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Comp_v2_0, CY_CONFIG_TITLE=Comp_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Comp_1, CY_INSTANCE_SHORT_NAME=Comp_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Comp_1, )
module Comp_v2_0_1 (
    Vplus,
    CmpOut,
    Vminus,
    clock);
    inout       Vplus;
    electrical  Vplus;
    output      CmpOut;
    inout       Vminus;
    electrical  Vminus;
    input       clock;


          wire  Net_9;
          wire  Net_1;

    cy_psoc3_ctcomp_v1_0 ctComp (
        .vplus(Vplus),
        .vminus(Vminus),
        .cmpout(Net_1),
        .clk_udb(clock),
        .clock(clock));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign CmpOut = Net_1;


    assign Net_9 = ~Net_1;



endmodule

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// VDAC8_v1_90(Data_Source=0, Initial_Value=87, Strobe_Mode=0, VDAC_Range=4, VDAC_Speed=0, Voltage=1392, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONFIG_TITLE=VDAC8_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC8_1, CY_INSTANCE_SHORT_NAME=VDAC8_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=VDAC8_1, )
module VDAC8_v1_90_2 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 0;
    parameter Initial_Value = 87;
    parameter Strobe_Mode = 0;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 0;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// OpAmp_v1_90(Mode=0, Power=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=OpAmp_v1_90, CY_CONFIG_TITLE=Opamp_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Opamp_1, CY_INSTANCE_SHORT_NAME=Opamp_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Opamp_1, )
module OpAmp_v1_90_3 (
    Vplus,
    Vout,
    Vminus);
    inout       Vplus;
    electrical  Vplus;
    inout       Vout;
    electrical  Vout;
    inout       Vminus;
    electrical  Vminus;

    parameter Mode = 0;

    electrical  Net_29;

    cy_psoc3_abuf_v1_0 ABuf (
        .vplus(Vplus),
        .vminus(Net_29),
        .vout(Vout));

	// abuf_negInput_mux (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 abuf_negInput_mux_connect(Net_29, Vminus);
	defparam abuf_negInput_mux_connect.sig_width = 1;



endmodule

// Component: xor_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\xor_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\xor_v1_0\xor_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\xor_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\xor_v1_0\xor_v1_0.v"
`endif

// Component: cydff_v1_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cydff_v1_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cydff_v1_30\cydff_v1_30.v"
`endif

// Component: GlitchFilter_v2_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0\GlitchFilter_v2_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0\GlitchFilter_v2_0.v"
`endif

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: B_Counter_v3_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`endif

// Counter_v3_0(CaptureMode=3, CaptureModeSoftware=0, ClockMode=0, CompareMode=4, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=4, CONTROL3=0, ControlRegRemoved=1, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=1, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=254, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=true, ReloadOnCompare=false, ReloadOnOverUnder=false, ReloadOnReset=false, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=Waiter, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Waiter, CY_INSTANCE_SHORT_NAME=Waiter, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Waiter, )
module Counter_v3_0_4 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 3;
    parameter ClockMode = 0;
    parameter CompareMode = 4;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 1;
    parameter ReloadOnCapture = 1;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 0;
    parameter ReloadOnReset = 0;
    parameter Resolution = 8;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = Net_102;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 3;
    defparam CounterUDB.ClockMode = 0;
    defparam CounterUDB.CompareMode = 4;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 1;
    defparam CounterUDB.ReloadOnCapture = 1;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 0;
    defparam CounterUDB.ReloadOnReset = 0;
    defparam CounterUDB.Resolution = 8;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=4, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=31, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=2, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=32, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=false, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=BitCounterDec, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=BitCounterDec, CY_INSTANCE_SHORT_NAME=BitCounterDec, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=BitCounterDec, )
module Counter_v3_0_5 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 0;
    parameter CompareMode = 4;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 2;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 0;
    parameter Resolution = 8;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 0;
    defparam CounterUDB.CompareMode = 4;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 2;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 0;
    defparam CounterUDB.Resolution = 8;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: BShiftReg_v2_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\BShiftReg_v2_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\BShiftReg_v2_30\BShiftReg_v2_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\BShiftReg_v2_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\BShiftReg_v2_30\BShiftReg_v2_30.v"
`endif

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, DefSi=0, Direction=0, FifoSize=4, InterruptSource=2, Length=32, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, UseInputFifo=false, UseInterrupt=true, UseOutputFifo=true, UseShiftIn=true, UseShiftOut=false, VerilogSectionReplacementString=sC32, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=RecieveShiftReg, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=RecieveShiftReg, CY_INSTANCE_SHORT_NAME=RecieveShiftReg, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=RecieveShiftReg, )
module ShiftReg_v2_30_6 (
    shift_in,
    load,
    store,
    clock,
    reset,
    shift_out,
    interrupt);
    input       shift_in;
    input       load;
    input       store;
    input       clock;
    input       reset;
    output      shift_out;
    output      interrupt;

    parameter Direction = 0;
    parameter FifoSize = 4;
    parameter Length = 32;

          wire  Net_2;
          wire  Net_1;
          wire  Net_350;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_350 = shift_in;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1));

    OneTerminal OneTerminal_1 (
        .o(Net_2));

    BShiftReg_v2_30 bSR (
        .shiftIn(Net_350),
        .load(load),
        .shiftOut(shift_out),
        .store(store),
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt));
    defparam bSR.DefSi = 0;
    defparam bSR.Direction = 0;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 2;
    defparam bSR.Length = 32;
    defparam bSR.UseInputFifo = 0;
    defparam bSR.UseInterrupt = 1;
    defparam bSR.UseOutputFifo = 1;



endmodule

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, DefSi=1, Direction=0, FifoSize=4, InterruptSource=1, Length=32, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, UseInputFifo=true, UseInterrupt=true, UseOutputFifo=false, UseShiftIn=false, UseShiftOut=true, VerilogSectionReplacementString=sC32, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=TransmitShiftReg, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=TransmitShiftReg, CY_INSTANCE_SHORT_NAME=TransmitShiftReg, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=TransmitShiftReg, )
module ShiftReg_v2_30_7 (
    shift_in,
    load,
    store,
    clock,
    reset,
    shift_out,
    interrupt);
    input       shift_in;
    input       load;
    input       store;
    input       clock;
    input       reset;
    output      shift_out;
    output      interrupt;

    parameter Direction = 0;
    parameter FifoSize = 4;
    parameter Length = 32;

          wire  Net_2;
          wire  Net_1;
          wire  Net_350;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_350 = Net_2;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1));

    OneTerminal OneTerminal_1 (
        .o(Net_2));

    BShiftReg_v2_30 bSR (
        .shiftIn(Net_350),
        .load(load),
        .shiftOut(shift_out),
        .store(store),
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt));
    defparam bSR.DefSi = 1;
    defparam bSR.Direction = 0;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 1;
    defparam bSR.Length = 32;
    defparam bSR.UseInputFifo = 1;
    defparam bSR.UseInterrupt = 1;
    defparam bSR.UseOutputFifo = 0;



endmodule

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: CyStatusReg_v1_90
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`endif

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=4, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=31, CONTROL3=0, ControlRegRemoved=1, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=1, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=true, InterruptOnTC=false, Period=32, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=false, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=BitCounterEnc, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=BitCounterEnc, CY_INSTANCE_SHORT_NAME=BitCounterEnc, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=BitCounterEnc, )
module Counter_v3_0_8 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 0;
    parameter CompareMode = 4;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 1;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 0;
    parameter Resolution = 8;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = Net_102;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 0;
    defparam CounterUDB.CompareMode = 4;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 1;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 0;
    defparam CounterUDB.Resolution = 8;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DefSi=0, Direction=1, FifoSize=4, InterruptSource=1, Length=8, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, UseInputFifo=true, UseInterrupt=false, UseOutputFifo=false, UseShiftIn=true, UseShiftOut=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=Period, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Period, CY_INSTANCE_SHORT_NAME=Period, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Period, )
module ShiftReg_v2_30_9 (
    shift_in,
    load,
    store,
    clock,
    reset,
    shift_out,
    interrupt);
    input       shift_in;
    input       load;
    input       store;
    input       clock;
    input       reset;
    output      shift_out;
    output      interrupt;

    parameter Direction = 1;
    parameter FifoSize = 4;
    parameter Length = 8;

          wire  Net_2;
          wire  Net_1;
          wire  Net_350;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_350 = shift_in;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1));

    OneTerminal OneTerminal_1 (
        .o(Net_2));

    BShiftReg_v2_30 bSR (
        .shiftIn(Net_350),
        .load(load),
        .shiftOut(shift_out),
        .store(store),
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt));
    defparam bSR.DefSi = 0;
    defparam bSR.Direction = 1;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 1;
    defparam bSR.Length = 8;
    defparam bSR.UseInputFifo = 1;
    defparam bSR.UseInterrupt = 0;
    defparam bSR.UseOutputFifo = 0;



endmodule

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DefSi=0, Direction=1, FifoSize=4, InterruptSource=0, Length=8, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, UseInputFifo=false, UseInterrupt=false, UseOutputFifo=false, UseShiftIn=true, UseShiftOut=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=SigmaReg, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SigmaReg, CY_INSTANCE_SHORT_NAME=SigmaReg, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=SigmaReg, )
module ShiftReg_v2_30_10 (
    shift_in,
    load,
    store,
    clock,
    reset,
    shift_out,
    interrupt);
    input       shift_in;
    input       load;
    input       store;
    input       clock;
    input       reset;
    output      shift_out;
    output      interrupt;

    parameter Direction = 1;
    parameter FifoSize = 4;
    parameter Length = 8;

          wire  Net_2;
          wire  Net_1;
          wire  Net_350;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_350 = shift_in;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1));

    OneTerminal OneTerminal_1 (
        .o(Net_2));

    BShiftReg_v2_30 bSR (
        .shiftIn(Net_350),
        .load(load),
        .shiftOut(shift_out),
        .store(store),
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt));
    defparam bSR.DefSi = 0;
    defparam bSR.Direction = 1;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 0;
    defparam bSR.Length = 8;
    defparam bSR.UseInputFifo = 0;
    defparam bSR.UseInterrupt = 0;
    defparam bSR.UseOutputFifo = 0;



endmodule

// Component: LUT_v1_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\LUT_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\LUT_v1_50\LUT_v1_50.v"
`endif

// Counter_v3_0(CaptureMode=1, CaptureModeSoftware=0, ClockMode=0, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=512, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=true, InterruptOnCompare=true, InterruptOnOverUnderFlow=true, InterruptOnTC=false, Period=4095, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=false, Resolution=16, RunMode=0, UDB16=true, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=usec_counter, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=usec_counter, CY_INSTANCE_SHORT_NAME=usec_counter, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=usec_counter, )
module Counter_v3_0_11 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 1;
    parameter ClockMode = 0;
    parameter CompareMode = 0;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 0;
    parameter Resolution = 16;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 1;
    defparam CounterUDB.ClockMode = 0;
    defparam CounterUDB.CompareMode = 0;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 0;
    defparam CounterUDB.Resolution = 16;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=3, CONTROL3=1, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FF16=false, FF8=true, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=7, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=Boundary8bit, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Boundary8bit, CY_INSTANCE_SHORT_NAME=Boundary8bit, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Boundary8bit, )
module Counter_v3_0_12 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 0;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 8;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

    cy_psoc3_timer_v1_0 CounterHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_91),
        .kill(Net_82),
        .clock(clock),
        .tc(Net_48),
        .compare(Net_47),
        .interrupt(Net_42));

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_42;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_48;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));



endmodule

// top
module top ;

          wire  Net_11244;
          wire [7:0] Net_11194;
          wire  Net_11193;
          wire  Net_11192;
          wire [1:1] FrameRX;
          wire  Net_11191;
          wire  Net_11190;
          wire  Net_11189;
          wire  Net_11188;
          wire  Net_11187;
          wire  Net_11186;
          wire  Net_11185;
          wire [0:0] Data;
          wire  Net_11184;
          wire  Net_11183;
          wire  Net_11182;
          wire  Net_11181;
          wire  Net_11180;
          wire  Net_11179;
          wire  Net_11178;
          wire  Net_11177;
          wire  Net_11176;
          wire  Net_11175;
          wire  Net_11290;
          wire  Net_11263;
          wire  Net_11262;
          wire  Net_11261;
          wire  Net_11260;
          wire  Net_11259;
          wire  Net_11258;
          wire  Net_11257;
          wire  Net_11256;
          wire  Net_11255;
          wire  Net_11156;
          wire  Net_11155;
          wire [0:0] Data_sync;
          wire  Net_11154;
          wire  Net_11153;
          wire  Net_11207;
          wire  Net_11068;
          wire  Net_11152;
          wire  Net_11151;
          wire [1:1] Frame_clear;
          wire  Net_11150;
          wire  Net_11149;
          wire  Net_11148;
          wire  Net_11147;
          wire  Net_11146;
          wire  Net_11145;
          wire  Net_11144;
          wire  Net_11143;
          wire  Net_11142;
          wire  Net_11141;
          wire  Net_11140;
          wire  S;
          wire  Net_11139;
          wire  Net_11138;
          wire  Net_11137;
          wire  Net_11136;
          wire  Net_11135;
          wire  Net_11134;
          wire  Net_11133;
          wire  Net_11132;
          wire  Net_11131;
          wire  Net_11312;
          wire [2:0] preouts;
          wire  Net_11311;
          wire  Net_11309;
          wire  Net_11008;
          wire [7:0] Net_11124;
          wire  Net_11123;
          wire [2:0] My_wire;
          wire  Net_11122;
          wire  Net_11121;
          wire  Net_11120;
          wire  Net_11119;
          wire  Net_11118;
          wire  Net_11117;
          wire  Net_11116;
          wire  Net_11115;
          wire  Net_10811;
          wire  Net_10810;
          wire  Net_10809;
          wire  Net_10808;
          wire  Net_10807;
          wire  Net_10806;
          wire  Net_10804;
          wire  Net_10803;
          wire  Net_10802;
          wire  Net_10829;
          wire  Net_11114;
          wire  Net_11113;
          wire  Net_11112;
          wire  Net_10538;
          wire  Net_10537;
          wire  Net_10536;
          wire  Net_10535;
          wire  Net_11057;
          wire  Net_10534;
          wire  Net_10533;
          wire  Net_10532;
          wire  Net_10531;
          wire  Net_10530;
          wire  Net_10529;
          wire  Net_10528;
          wire  Net_10527;
          wire  Net_10526;
          wire [7:0] Net_10560;
          wire  Net_10559;
          wire  Net_10558;
          wire  Net_10557;
          wire  Net_10556;
          wire  Net_10555;
          wire  Net_10553;
          wire  n123;
          wire  Net_10552;
          wire  Net_10551;
    electrical  Net_10561;
    electrical  Net_10562;
          wire  Net_10554;
          wire  Net_10691;
          wire  Net_10690;
          wire  Net_10689;
          wire  Net_10260;
          wire  Net_10047;
          wire  Net_10831;
          wire  Net_10827;
          wire  Net_7167;
          wire  Net_7166;
          wire  Net_7163;
          wire  Net_7130;
          wire  n124;
          wire  Net_7129;
          wire  Net_7128;
          wire  Net_7127;
          wire  Net_7125;
          wire  Net_7122;
          wire  Net_3939;
          wire  Net_3010;
          wire  Net_3009;
          wire  Net_3008;
          wire  Net_3005;
          wire  Net_3002;
          wire  Net_10592;
          wire  Net_10591;
          wire  Net_10590;
          wire  Net_10589;
          wire  Net_10588;
          wire  Net_10587;
          wire  Net_10585;
          wire  Net_10593;
          wire  Net_10584;
          wire  Net_11111;
          wire  Net_7070;
          wire  Net_7072;
          wire [7:0] Net_7065;
          wire  Net_7064;
    electrical  Net_7063;
    electrical  Net_7062;
    electrical  Net_7061;
          wire  Net_7067;
          wire  Net_7069;
          wire  Net_10925;
          wire  Net_11303;
          wire  Net_11293;
          wire  Net_11292;
          wire  Net_11269;
          wire  Net_11403;
          wire  Net_11310;
          wire  Net_10946;
          wire  Net_11009;
          wire  Net_11018;
          wire  Net_819;
          wire  Net_698;
          wire  Net_860;
          wire  Net_11246;
          wire  Net_677;
          wire  Net_686;
          wire  Net_11393;
          wire  Net_11125;
          wire  Net_9581;
          wire  Net_10720;
          wire  Net_1453;
          wire  Net_10896;
          wire  Net_10862;
          wire  Net_10842;
          wire  Net_3004;
          wire  Net_1037;
          wire  Net_3003;
          wire  Net_4484;
          wire  Net_10805;
          wire  Net_7168;
          wire  Net_7164;
          wire  Net_10771;
          wire  Net_10511;
          wire  Net_10746;
    electrical  Net_10739;
          wire  Net_1463;
          wire  Net_10731;
          wire  Net_10696;
          wire  Net_10679;
          wire  Net_10625;
          wire  Net_9761;
          wire  Net_9792;
          wire  Net_7248;
          wire  Net_10667;
          wire  Net_10649;
          wire  Net_10480;
          wire  Net_10110;
          wire  Net_10749;
          wire  Net_10457;
          wire  Net_7404;
          wire  Net_10452;
          wire  Net_10449;
    electrical  Net_70;
          wire  Net_110;
          wire  Net_103;
          wire  Net_1485;
          wire  Net_10124;
          wire  Net_10779;
          wire  Net_3360;
          wire  Net_2241;
          wire  Net_104;
    electrical  Net_58;
    electrical  Net_73;
    electrical  Net_53;
    electrical  Net_54;
          wire  Mhz4_096;
    electrical  Net_63;
    electrical  Net_43;
          wire  Net_5580;
          wire  Net_5249;

	wire [0:0] tmpOE__DInN_net;
	wire [0:0] tmpFB_0__DInN_net;
	wire [0:0] tmpIO_0__DInN_net;
	wire [0:0] tmpINTERRUPT_0__DInN_net;
	electrical [0:0] tmpSIOVREF__DInN_net;

	cy_psoc3_pins_v1_10
		#(.id("ad216d65-d721-47ad-b390-994c64fc41b7"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DInN
		 (.oe(tmpOE__DInN_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__DInN_net[0:0]}),
		  .analog({Net_58}),
		  .io({tmpIO_0__DInN_net[0:0]}),
		  .siovref(tmpSIOVREF__DInN_net),
		  .interrupt({tmpINTERRUPT_0__DInN_net[0:0]}),
		  .annotation({Net_53}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DInN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_53,
            Net_54
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;


	cy_vref_v1_0
		#(.guid("4720866E-BC14-478d-B8A0-3E44F38CADAC"),
		  .name("Vdda/2"),
		  .autoenable(1))
		vRef_1
		 (.vout(Net_43));


    Comp_v2_0_0 Comp_2 (
        .Vplus(Net_73),
        .CmpOut(n124),
        .Vminus(Net_10739),
        .clock(1'b0));

	wire [0:0] tmpOE__Vout_1_net;
	wire [0:0] tmpFB_0__Vout_1_net;
	wire [0:0] tmpIO_0__Vout_1_net;
	wire [0:0] tmpINTERRUPT_0__Vout_1_net;
	electrical [0:0] tmpSIOVREF__Vout_1_net;

	cy_psoc3_pins_v1_10
		#(.id("cc3bcd7e-5dc0-48ea-9bf6-6aa082be1ada"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Vout_1
		 (.oe(tmpOE__Vout_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Vout_1_net[0:0]}),
		  .analog({Net_63}),
		  .io({tmpIO_0__Vout_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Vout_1_net),
		  .interrupt({tmpINTERRUPT_0__Vout_1_net[0:0]}),
		  .annotation({Net_70}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Vout_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DInP_net;
	wire [0:0] tmpFB_0__DInP_net;
	wire [0:0] tmpIO_0__DInP_net;
	wire [0:0] tmpINTERRUPT_0__DInP_net;
	electrical [0:0] tmpSIOVREF__DInP_net;

	cy_psoc3_pins_v1_10
		#(.id("dc289d35-d461-4f36-aec1-f6608f41166c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DInP
		 (.oe(tmpOE__DInP_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__DInP_net[0:0]}),
		  .analog({Net_10739}),
		  .io({tmpIO_0__DInP_net[0:0]}),
		  .siovref(tmpSIOVREF__DInP_net),
		  .interrupt({tmpINTERRUPT_0__DInP_net[0:0]}),
		  .annotation({Net_54}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DInP_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Comp_v2_0_1 Comp_1 (
        .Vplus(Net_73),
        .CmpOut(n123),
        .Vminus(Net_58),
        .clock(1'b0));

    cy_annotation_universal_v1_0 T_2 (
        .connect({
            Net_54,
            Net_53,
            Net_70,
            Net_7061,
            Net_7062,
            Net_7063
        })
    );
    defparam T_2.comp_name = "Transformer_v1_0";
    defparam T_2.port_names = "P1, P2, PCT, S1, S2, SCT";
    defparam T_2.width = 6;

    VDAC8_v1_90_2 VDAC8_1 (
        .strobe(1'b0),
        .data(8'b00000000),
        .vOut(Net_73));
    defparam VDAC8_1.Data_Source = 0;
    defparam VDAC8_1.Initial_Value = 87;
    defparam VDAC8_1.Strobe_Mode = 0;

    OpAmp_v1_90_3 Opamp_1 (
        .Vplus(Net_43),
        .Vout(Net_63),
        .Vminus(Net_63));
    defparam Opamp_1.Mode = 0;


    assign FrameRX[1] = Net_103 ^ Net_104;


    assign Data[0] = Net_103 ^ Net_110;

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge Net_10449)
    begin
        cydff_1 <= Net_104;
    end
    assign Net_110 = cydff_1;
    // -- DFF End --

    GlitchFilter_v2_0 GlitchFilter_1 (
        .d(Data[0]),
        .reset(1'b0),
        .clock(Net_7070),
        .q(Data_sync[0]));
    defparam GlitchFilter_1.BypassFilter = 0;
    defparam GlitchFilter_1.GlitchLength = 1;
    defparam GlitchFilter_1.SignalWidth = 1;

	wire [0:0] tmpOE__LOAD_net;
	wire [0:0] tmpFB_0__LOAD_net;
	wire [0:0] tmpIO_0__LOAD_net;
	wire [0:0] tmpINTERRUPT_0__LOAD_net;
	electrical [0:0] tmpSIOVREF__LOAD_net;

	cy_psoc3_pins_v1_10
		#(.id("aa4cd9ec-d2b0-4c80-8fe6-7f54840242c1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		LOAD
		 (.oe(tmpOE__LOAD_net),
		  .y({Net_10625}),
		  .fb({tmpFB_0__LOAD_net[0:0]}),
		  .io({tmpIO_0__LOAD_net[0:0]}),
		  .siovref(tmpSIOVREF__LOAD_net),
		  .interrupt({tmpINTERRUPT_0__LOAD_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LOAD_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("92638c71-d3ee-4bf8-af13-ac4852464d3e"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_4
		 (.clock_out(Net_9581));


	wire [0:0] tmpOE__Sh_out_net;
	wire [0:0] tmpFB_0__Sh_out_net;
	wire [0:0] tmpIO_0__Sh_out_net;
	wire [0:0] tmpINTERRUPT_0__Sh_out_net;
	electrical [0:0] tmpSIOVREF__Sh_out_net;

	cy_psoc3_pins_v1_10
		#(.id("dad38982-1d6f-43cc-8f8c-b8e591d5e963"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sh_out
		 (.oe(tmpOE__Sh_out_net),
		  .y({Net_10649}),
		  .fb({tmpFB_0__Sh_out_net[0:0]}),
		  .io({tmpIO_0__Sh_out_net[0:0]}),
		  .siovref(tmpSIOVREF__Sh_out_net),
		  .interrupt({tmpINTERRUPT_0__Sh_out_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sh_out_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_80 FrameAllow (
        .control_1(Net_10584),
        .control_2(Net_10593),
        .control_3(Net_10585),
        .control_0(Net_7248),
        .control_4(Net_10587),
        .control_5(Net_10588),
        .control_6(Net_10589),
        .control_7(Net_10590),
        .clock(1'b0),
        .reset(1'b0));
    defparam FrameAllow.Bit0Mode = 0;
    defparam FrameAllow.Bit1Mode = 0;
    defparam FrameAllow.Bit2Mode = 0;
    defparam FrameAllow.Bit3Mode = 0;
    defparam FrameAllow.Bit4Mode = 0;
    defparam FrameAllow.Bit5Mode = 0;
    defparam FrameAllow.Bit6Mode = 0;
    defparam FrameAllow.Bit7Mode = 0;
    defparam FrameAllow.BitValue = 0;
    defparam FrameAllow.BusDisplay = 0;
    defparam FrameAllow.ExtrReset = 0;
    defparam FrameAllow.NumOutputs = 1;


    assign S = Net_10649 ^ Net_10749;


    assign Net_1485 = Net_10124 & Data_sync[0];

    Counter_v3_0_4 Waiter (
        .reset(Net_10779),
        .tc(Net_3002),
        .comp(Net_3003),
        .clock(Net_10842),
        .interrupt(Net_3005),
        .enable(Net_10124),
        .capture(Net_1485),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_4484));
    defparam Waiter.CaptureMode = 3;
    defparam Waiter.ClockMode = 0;
    defparam Waiter.CompareMode = 4;
    defparam Waiter.CompareStatusEdgeSense = 1;
    defparam Waiter.EnableMode = 1;
    defparam Waiter.ReloadOnCapture = 1;
    defparam Waiter.ReloadOnCompare = 0;
    defparam Waiter.ReloadOnOverUnder = 0;
    defparam Waiter.ReloadOnReset = 0;
    defparam Waiter.Resolution = 8;
    defparam Waiter.RunMode = 0;
    defparam Waiter.UseInterrupt = 1;


	cy_clock_v1_0
		#(.id("0feb943a-bf8d-457b-8b44-ba0833106cbd"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("27777777.7777778"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_2
		 (.clock_out(Net_4484));



    assign Net_10124 = ~Net_10779;

    // -- DFF Start --
    reg  cydff_2;
    always @(posedge Net_10779 or posedge Net_3003)
    begin
        if (Net_10779)
        begin
            cydff_2 <= ~0;
        end
        else
        begin
            cydff_2 <= Net_5249;
        end
    end
    assign Net_5580 = cydff_2;
    // -- DFF End --


    assign Net_5249 = ~Net_5580;


    assign Net_10771 = Net_1485 ^ Net_5580;

    Counter_v3_0_5 BitCounterDec (
        .reset(Net_10779),
        .tc(Net_7122),
        .comp(Net_7164),
        .clock(Net_10862),
        .interrupt(Net_7125),
        .enable(Net_10124),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_10771));
    defparam BitCounterDec.CaptureMode = 0;
    defparam BitCounterDec.ClockMode = 0;
    defparam BitCounterDec.CompareMode = 4;
    defparam BitCounterDec.CompareStatusEdgeSense = 1;
    defparam BitCounterDec.EnableMode = 2;
    defparam BitCounterDec.ReloadOnCapture = 0;
    defparam BitCounterDec.ReloadOnCompare = 0;
    defparam BitCounterDec.ReloadOnOverUnder = 1;
    defparam BitCounterDec.ReloadOnReset = 0;
    defparam BitCounterDec.Resolution = 8;
    defparam BitCounterDec.RunMode = 0;
    defparam BitCounterDec.UseInterrupt = 1;

    ShiftReg_v2_30_6 RecieveShiftReg (
        .shift_in(Net_5580),
        .load(1'b0),
        .store(Net_7164),
        .clock(Net_10771),
        .reset(1'b0),
        .shift_out(Net_7167),
        .interrupt(Net_7168));
    defparam RecieveShiftReg.Direction = 0;
    defparam RecieveShiftReg.FifoSize = 4;
    defparam RecieveShiftReg.Length = 32;

	wire [0:0] tmpOE__LOAD_int_net;
	wire [0:0] tmpFB_0__LOAD_int_net;
	wire [0:0] tmpIO_0__LOAD_int_net;
	wire [0:0] tmpINTERRUPT_0__LOAD_int_net;
	electrical [0:0] tmpSIOVREF__LOAD_int_net;

	cy_psoc3_pins_v1_10
		#(.id("48a2a54f-9f3b-4e78-bbd2-d16b1f62eb35"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		LOAD_int
		 (.oe(tmpOE__LOAD_int_net),
		  .y({Net_7168}),
		  .fb({tmpFB_0__LOAD_int_net[0:0]}),
		  .io({tmpIO_0__LOAD_int_net[0:0]}),
		  .siovref(tmpSIOVREF__LOAD_int_net),
		  .interrupt({tmpINTERRUPT_0__LOAD_int_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LOAD_int_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		WordShifted
		 (.int_signal(Net_7168));



	cy_clock_v1_0
		#(.id("3de63e2f-009e-4e0a-b688-6e2dad875b28"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_3
		 (.clock_out(Net_3360));


	wire [0:0] tmpOE__TC_net;
	wire [0:0] tmpFB_0__TC_net;
	wire [0:0] tmpIO_0__TC_net;
	wire [0:0] tmpINTERRUPT_0__TC_net;
	electrical [0:0] tmpSIOVREF__TC_net;

	cy_psoc3_pins_v1_10
		#(.id("69c4927a-cfee-4b39-be28-a575e52608dc"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		TC
		 (.oe(tmpOE__TC_net),
		  .y({Net_10667}),
		  .fb({tmpFB_0__TC_net[0:0]}),
		  .io({tmpIO_0__TC_net[0:0]}),
		  .siovref(tmpSIOVREF__TC_net),
		  .interrupt({tmpINTERRUPT_0__TC_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TC_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("808fc21e-de41-4a06-8312-4eecff54ccf8"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_7070));


	wire [0:0] tmpOE__Compare_net;
	wire [0:0] tmpFB_0__Compare_net;
	wire [0:0] tmpIO_0__Compare_net;
	wire [0:0] tmpINTERRUPT_0__Compare_net;
	electrical [0:0] tmpSIOVREF__Compare_net;

	cy_psoc3_pins_v1_10
		#(.id("177d187b-f9ff-4fdc-bc43-418f26c08243"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Compare
		 (.oe(tmpOE__Compare_net),
		  .y({Net_10679}),
		  .fb({tmpFB_0__Compare_net[0:0]}),
		  .io({tmpIO_0__Compare_net[0:0]}),
		  .siovref(tmpSIOVREF__Compare_net),
		  .interrupt({tmpINTERRUPT_0__Compare_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Compare_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_1463 = ~Net_10511;

	wire [0:0] tmpOE__ClockEncDelay_net;
	wire [0:0] tmpFB_0__ClockEncDelay_net;
	wire [0:0] tmpIO_0__ClockEncDelay_net;
	wire [0:0] tmpINTERRUPT_0__ClockEncDelay_net;
	electrical [0:0] tmpSIOVREF__ClockEncDelay_net;

	cy_psoc3_pins_v1_10
		#(.id("9baf6e5d-c961-404f-8bb3-34160dd1b29a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		ClockEncDelay
		 (.oe(tmpOE__ClockEncDelay_net),
		  .y({Net_10749}),
		  .fb({tmpFB_0__ClockEncDelay_net[0:0]}),
		  .io({tmpIO_0__ClockEncDelay_net[0:0]}),
		  .siovref(tmpSIOVREF__ClockEncDelay_net),
		  .interrupt({tmpINTERRUPT_0__ClockEncDelay_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ClockEncDelay_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_2241 = ~S;

	wire [0:0] tmpOE__DOut1P_net;
	wire [0:0] tmpFB_0__DOut1P_net;
	wire [0:0] tmpIO_0__DOut1P_net;
	wire [0:0] tmpINTERRUPT_0__DOut1P_net;
	electrical [0:0] tmpSIOVREF__DOut1P_net;

	cy_psoc3_pins_v1_10
		#(.id("2d1a92a4-f694-40aa-9a5a-76a2fc7a20a0"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DOut1P
		 (.oe(tmpOE__DOut1P_net),
		  .y({My_wire[1]}),
		  .fb({tmpFB_0__DOut1P_net[0:0]}),
		  .io({tmpIO_0__DOut1P_net[0:0]}),
		  .siovref(tmpSIOVREF__DOut1P_net),
		  .interrupt({tmpINTERRUPT_0__DOut1P_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DOut1P_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    GlitchFilter_v2_0 GlitchFilter_6 (
        .d(FrameRX[1]),
        .reset(1'b0),
        .clock(Net_3004),
        .q(Frame_clear[1]));
    defparam GlitchFilter_6.BypassFilter = 1;
    defparam GlitchFilter_6.GlitchLength = 10;
    defparam GlitchFilter_6.SignalWidth = 1;


    assign preouts[0] = Net_2241 & preouts[2];


    assign preouts[1] = S & preouts[2];

    GlitchFilter_v2_0 GlitchFilter_3 (
        .d(preouts[2:0]),
        .reset(1'b0),
        .clock(Net_3360),
        .q(My_wire[2:0]));
    defparam GlitchFilter_3.BypassFilter = 0;
    defparam GlitchFilter_3.GlitchLength = 1;
    defparam GlitchFilter_3.SignalWidth = 3;

	wire [0:0] tmpOE__EN1_net;
	wire [0:0] tmpFB_0__EN1_net;
	wire [0:0] tmpIO_0__EN1_net;
	wire [0:0] tmpINTERRUPT_0__EN1_net;
	electrical [0:0] tmpSIOVREF__EN1_net;

	cy_psoc3_pins_v1_10
		#(.id("6847f2fc-d5fa-4910-8f3d-8d45b5ceb563"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		EN1
		 (.oe(tmpOE__EN1_net),
		  .y({My_wire[2]}),
		  .fb({tmpFB_0__EN1_net[0:0]}),
		  .io({tmpIO_0__EN1_net[0:0]}),
		  .siovref(tmpSIOVREF__EN1_net),
		  .interrupt({tmpINTERRUPT_0__EN1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__EN1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DOut1N_net;
	wire [0:0] tmpFB_0__DOut1N_net;
	wire [0:0] tmpIO_0__DOut1N_net;
	wire [0:0] tmpINTERRUPT_0__DOut1N_net;
	electrical [0:0] tmpSIOVREF__DOut1N_net;

	cy_psoc3_pins_v1_10
		#(.id("ebc02dd0-519d-4a8e-a3ed-8da7309e851f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DOut1N
		 (.oe(tmpOE__DOut1N_net),
		  .y({My_wire[0]}),
		  .fb({tmpFB_0__DOut1N_net[0:0]}),
		  .io({tmpIO_0__DOut1N_net[0:0]}),
		  .siovref(tmpSIOVREF__DOut1N_net),
		  .interrupt({tmpINTERRUPT_0__DOut1N_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DOut1N_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_7404));

    ShiftReg_v2_30_7 TransmitShiftReg (
        .shift_in(1'b0),
        .load(Net_10625),
        .store(1'b0),
        .clock(Net_10749),
        .reset(1'b0),
        .shift_out(Net_10649),
        .interrupt(Net_10480));
    defparam TransmitShiftReg.Direction = 0;
    defparam TransmitShiftReg.FifoSize = 4;
    defparam TransmitShiftReg.Length = 32;

    assign Net_10554 = 1'h0;


    assign Net_9761 = ~Net_9792;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_10562
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 SW_1 (
        .connect({
            Net_10562,
            Net_10561
        })
    );
    defparam SW_1.comp_name = "SwitchSPST_v1_0";
    defparam SW_1.port_names = "T1, T2";
    defparam SW_1.width = 2;

	wire [0:0] tmpOE__Start_net;
	wire [0:0] tmpIO_0__Start_net;
	wire [0:0] tmpINTERRUPT_0__Start_net;
	electrical [0:0] tmpSIOVREF__Start_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Start
		 (.oe(tmpOE__Start_net),
		  .y({1'b0}),
		  .fb({Net_9792}),
		  .io({tmpIO_0__Start_net[0:0]}),
		  .siovref(tmpSIOVREF__Start_net),
		  .interrupt({tmpINTERRUPT_0__Start_net[0:0]}),
		  .annotation({Net_10561}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Start_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyStatusReg_v1_90 StartButton (
        .status_0(Net_9761),
        .status_1(1'b0),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Net_10554),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_10559),
        .status_bus(8'b0));
    defparam StartButton.Bit0Mode = 0;
    defparam StartButton.Bit1Mode = 0;
    defparam StartButton.Bit2Mode = 0;
    defparam StartButton.Bit3Mode = 0;
    defparam StartButton.Bit4Mode = 0;
    defparam StartButton.Bit5Mode = 0;
    defparam StartButton.Bit6Mode = 0;
    defparam StartButton.Bit7Mode = 0;
    defparam StartButton.BusDisplay = 0;
    defparam StartButton.Interrupt = 0;
    defparam StartButton.MaskValue = 0;
    defparam StartButton.NumInputs = 1;

	wire [0:0] tmpOE__BitCounterDec_comp_net;
	wire [0:0] tmpFB_0__BitCounterDec_comp_net;
	wire [0:0] tmpIO_0__BitCounterDec_comp_net;
	wire [0:0] tmpINTERRUPT_0__BitCounterDec_comp_net;
	electrical [0:0] tmpSIOVREF__BitCounterDec_comp_net;

	cy_psoc3_pins_v1_10
		#(.id("78271083-2b24-4a28-931c-d77680400fff"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BitCounterDec_comp
		 (.oe(tmpOE__BitCounterDec_comp_net),
		  .y({Net_7164}),
		  .fb({tmpFB_0__BitCounterDec_comp_net[0:0]}),
		  .io({tmpIO_0__BitCounterDec_comp_net[0:0]}),
		  .siovref(tmpSIOVREF__BitCounterDec_comp_net),
		  .interrupt({tmpINTERRUPT_0__BitCounterDec_comp_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BitCounterDec_comp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Sh_in_net;
	wire [0:0] tmpFB_0__Sh_in_net;
	wire [0:0] tmpIO_0__Sh_in_net;
	wire [0:0] tmpINTERRUPT_0__Sh_in_net;
	electrical [0:0] tmpSIOVREF__Sh_in_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Sh_in
		 (.oe(tmpOE__Sh_in_net),
		  .y({Net_5580}),
		  .fb({tmpFB_0__Sh_in_net[0:0]}),
		  .io({tmpIO_0__Sh_in_net[0:0]}),
		  .siovref(tmpSIOVREF__Sh_in_net),
		  .interrupt({tmpINTERRUPT_0__Sh_in_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Sh_in_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__BitCounter_in_net;
	wire [0:0] tmpFB_0__BitCounter_in_net;
	wire [0:0] tmpIO_0__BitCounter_in_net;
	wire [0:0] tmpINTERRUPT_0__BitCounter_in_net;
	electrical [0:0] tmpSIOVREF__BitCounter_in_net;

	cy_psoc3_pins_v1_10
		#(.id("f85f0990-0193-4986-a4dd-ccfc14d9dfab"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BitCounter_in
		 (.oe(tmpOE__BitCounter_in_net),
		  .y({Net_10771}),
		  .fb({tmpFB_0__BitCounter_in_net[0:0]}),
		  .io({tmpIO_0__BitCounter_in_net[0:0]}),
		  .siovref(tmpSIOVREF__BitCounter_in_net),
		  .interrupt({tmpINTERRUPT_0__BitCounter_in_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BitCounter_in_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_10779 = ~Frame_clear[1];

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_104 = n124;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_103 = n123;

    // -- DFF Start --
    reg  cydff_12;
    always @(posedge Net_1463 or posedge Net_10749)
    begin
        if (Net_1463)
        begin
            cydff_12 <= 0;
        end
        else
        begin
            cydff_12 <= Net_7248;
        end
    end
    assign preouts[2] = cydff_12;
    // -- DFF End --

	wire [0:0] tmpOE__Data_in_net;
	wire [0:0] tmpFB_0__Data_in_net;
	wire [0:0] tmpIO_0__Data_in_net;
	wire [0:0] tmpINTERRUPT_0__Data_in_net;
	electrical [0:0] tmpSIOVREF__Data_in_net;

	cy_psoc3_pins_v1_10
		#(.id("e146f9e9-44bc-45db-92be-40a7608c2ca5"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Data_in
		 (.oe(tmpOE__Data_in_net),
		  .y({Net_1485}),
		  .fb({tmpFB_0__Data_in_net[0:0]}),
		  .io({tmpIO_0__Data_in_net[0:0]}),
		  .siovref(tmpSIOVREF__Data_in_net),
		  .interrupt({tmpINTERRUPT_0__Data_in_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Data_in_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		TransmitWordShift
		 (.int_signal(Net_10110));



	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_Load_TrShReg
		 (.int_signal(Net_10480));



    assign Net_10625 = Net_10679 & Net_10457;

    CyControlReg_v1_80 StartTransmit (
        .control_1(Net_10526),
        .control_2(Net_10527),
        .control_3(Net_10528),
        .control_0(Net_10457),
        .control_4(Net_10529),
        .control_5(Net_10530),
        .control_6(Net_10531),
        .control_7(Net_10532),
        .clock(1'b0),
        .reset(1'b0));
    defparam StartTransmit.Bit0Mode = 0;
    defparam StartTransmit.Bit1Mode = 0;
    defparam StartTransmit.Bit2Mode = 0;
    defparam StartTransmit.Bit3Mode = 0;
    defparam StartTransmit.Bit4Mode = 0;
    defparam StartTransmit.Bit5Mode = 0;
    defparam StartTransmit.Bit6Mode = 0;
    defparam StartTransmit.Bit7Mode = 0;
    defparam StartTransmit.BitValue = 0;
    defparam StartTransmit.BusDisplay = 0;
    defparam StartTransmit.ExtrReset = 0;
    defparam StartTransmit.NumOutputs = 1;

	wire [0:0] tmpOE__Pin_3_net;
	wire [0:0] tmpFB_0__Pin_3_net;
	wire [0:0] tmpIO_0__Pin_3_net;
	wire [0:0] tmpINTERRUPT_0__Pin_3_net;
	electrical [0:0] tmpSIOVREF__Pin_3_net;

	cy_psoc3_pins_v1_10
		#(.id("6182948e-2b0e-4565-acbb-92c11b85db20"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_3
		 (.oe(tmpOE__Pin_3_net),
		  .y({n123}),
		  .fb({tmpFB_0__Pin_3_net[0:0]}),
		  .io({tmpIO_0__Pin_3_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_3_net),
		  .interrupt({tmpINTERRUPT_0__Pin_3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_4_net;
	wire [0:0] tmpFB_0__Pin_4_net;
	wire [0:0] tmpIO_0__Pin_4_net;
	wire [0:0] tmpINTERRUPT_0__Pin_4_net;
	electrical [0:0] tmpSIOVREF__Pin_4_net;

	cy_psoc3_pins_v1_10
		#(.id("16d6b2f5-2558-469b-9968-13ea8155a98e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_4
		 (.oe(tmpOE__Pin_4_net),
		  .y({n124}),
		  .fb({tmpFB_0__Pin_4_net[0:0]}),
		  .io({tmpIO_0__Pin_4_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_4_net),
		  .interrupt({tmpINTERRUPT_0__Pin_4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_10449 = FrameRX[1] & Net_10452;


    assign Net_10452 = ~Frame_clear[1];

    Counter_v3_0_8 BitCounterEnc (
        .reset(1'b0),
        .tc(Net_10667),
        .comp(Net_10679),
        .clock(Net_9581),
        .interrupt(Net_10110),
        .enable(Net_10511),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_10749));
    defparam BitCounterEnc.CaptureMode = 0;
    defparam BitCounterEnc.ClockMode = 0;
    defparam BitCounterEnc.CompareMode = 4;
    defparam BitCounterEnc.CompareStatusEdgeSense = 1;
    defparam BitCounterEnc.EnableMode = 1;
    defparam BitCounterEnc.ReloadOnCapture = 0;
    defparam BitCounterEnc.ReloadOnCompare = 0;
    defparam BitCounterEnc.ReloadOnOverUnder = 1;
    defparam BitCounterEnc.ReloadOnReset = 0;
    defparam BitCounterEnc.Resolution = 8;
    defparam BitCounterEnc.RunMode = 0;
    defparam BitCounterEnc.UseInterrupt = 1;

    // -- DFF Start --
    reg  cydff_11;
    always @(posedge Net_10457 or posedge Net_10667)
    begin
        if (Net_10457)
        begin
            cydff_11 <= ~0;
        end
        else
        begin
            cydff_11 <= Net_7404;
        end
    end
    assign Net_10511 = cydff_11;
    // -- DFF End --

	wire [0:0] tmpOE__ClockEnc_net;
	wire [0:0] tmpFB_0__ClockEnc_net;
	wire [0:0] tmpIO_0__ClockEnc_net;
	wire [0:0] tmpINTERRUPT_0__ClockEnc_net;
	electrical [0:0] tmpSIOVREF__ClockEnc_net;

	cy_psoc3_pins_v1_10
		#(.id("43a62d2e-7bbf-47e1-abe2-1d3956528cbd"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		ClockEnc
		 (.oe(tmpOE__ClockEnc_net),
		  .y({Net_10749}),
		  .fb({tmpFB_0__ClockEnc_net[0:0]}),
		  .io({tmpIO_0__ClockEnc_net[0:0]}),
		  .siovref(tmpSIOVREF__ClockEnc_net),
		  .interrupt({tmpINTERRUPT_0__ClockEnc_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__ClockEnc_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LOAD_1_net;
	wire [0:0] tmpFB_0__LOAD_1_net;
	wire [0:0] tmpIO_0__LOAD_1_net;
	wire [0:0] tmpINTERRUPT_0__LOAD_1_net;
	electrical [0:0] tmpSIOVREF__LOAD_1_net;

	cy_psoc3_pins_v1_10
		#(.id("98f817e6-39df-47e5-81b0-0df90f707224"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		LOAD_1
		 (.oe(tmpOE__LOAD_1_net),
		  .y({Net_10480}),
		  .fb({tmpFB_0__LOAD_1_net[0:0]}),
		  .io({tmpIO_0__LOAD_1_net[0:0]}),
		  .siovref(tmpSIOVREF__LOAD_1_net),
		  .interrupt({tmpINTERRUPT_0__LOAD_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LOAD_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("3692bd59-6fb6-474d-981b-2cc328245c19"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_8
		 (.clock_out(Net_10862));



	cy_clock_v1_0
		#(.id("2f72d279-4171-419e-b129-d0f04a61a626"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_7
		 (.clock_out(Net_10842));



	cy_clock_v1_0
		#(.id("ef9d0457-9a44-46b2-ab48-40a996c03758"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_6
		 (.clock_out(Net_3004));


    // -- DFF Start --
    reg  cydff_5;
    always @(posedge Net_1463 or posedge Net_10896)
    begin
        if (Net_1463)
        begin
            cydff_5 <= ~0;
        end
        else
        begin
            cydff_5 <= Net_1037;
        end
    end
    assign Net_1453 = cydff_5;
    // -- DFF End --

    // -- DFF Start --
    reg  cydff_6;
    always @(posedge Net_1463 or posedge Net_10896)
    begin
        if (Net_1463)
        begin
            cydff_6 <= ~0;
        end
        else
        begin
            cydff_6 <= Net_10720;
        end
    end
    assign Net_1037 = cydff_6;
    // -- DFF End --


	cy_clock_v1_0
		#(.id("dcf6f238-b9df-475c-abec-17f8532a3239"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_5
		 (.clock_out(Net_10896));


    // -- DFF Start --
    reg  cydff_8;
    always @(posedge Net_1463 or posedge Net_1037)
    begin
        if (Net_1463)
        begin
            cydff_8 <= ~0;
        end
        else
        begin
            cydff_8 <= Net_10731;
        end
    end
    assign Net_10696 = cydff_8;
    // -- DFF End --


    assign Net_10731 = ~Net_10696;

	wire [0:0] tmpOE__Frame_in_net;
	wire [0:0] tmpFB_0__Frame_in_net;
	wire [0:0] tmpIO_0__Frame_in_net;
	wire [0:0] tmpINTERRUPT_0__Frame_in_net;
	electrical [0:0] tmpSIOVREF__Frame_in_net;

	cy_psoc3_pins_v1_10
		#(.id("b6ef75aa-e701-4565-8d71-bb2cb26e5d4b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Frame_in
		 (.oe(tmpOE__Frame_in_net),
		  .y({Net_10124}),
		  .fb({tmpFB_0__Frame_in_net[0:0]}),
		  .io({tmpIO_0__Frame_in_net[0:0]}),
		  .siovref(tmpSIOVREF__Frame_in_net),
		  .interrupt({tmpINTERRUPT_0__Frame_in_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Frame_in_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- DFF Start --
    reg  cydff_3;
    always @(posedge Net_1463 or posedge Net_10696)
    begin
        if (Net_1463)
        begin
            cydff_3 <= ~0;
        end
        else
        begin
            cydff_3 <= Net_10746;
        end
    end
    assign Net_10749 = cydff_3;
    // -- DFF End --


    assign Net_10746 = ~Net_10749;

	wire [0:0] tmpOE__TC_Dec_Bit_net;
	wire [0:0] tmpFB_0__TC_Dec_Bit_net;
	wire [0:0] tmpIO_0__TC_Dec_Bit_net;
	wire [0:0] tmpINTERRUPT_0__TC_Dec_Bit_net;
	electrical [0:0] tmpSIOVREF__TC_Dec_Bit_net;

	cy_psoc3_pins_v1_10
		#(.id("3d2009b5-4d73-40d0-b417-f5c199bb5fe1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		TC_Dec_Bit
		 (.oe(tmpOE__TC_Dec_Bit_net),
		  .y({Net_7122}),
		  .fb({tmpFB_0__TC_Dec_Bit_net[0:0]}),
		  .io({tmpIO_0__TC_Dec_Bit_net[0:0]}),
		  .siovref(tmpSIOVREF__TC_Dec_Bit_net),
		  .interrupt({tmpINTERRUPT_0__TC_Dec_Bit_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TC_Dec_Bit_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Compare_wait_net;
	wire [0:0] tmpFB_0__Compare_wait_net;
	wire [0:0] tmpIO_0__Compare_wait_net;
	wire [0:0] tmpINTERRUPT_0__Compare_wait_net;
	electrical [0:0] tmpSIOVREF__Compare_wait_net;

	cy_psoc3_pins_v1_10
		#(.id("581fe94e-1a77-4432-a5f0-0f8692f00719"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Compare_wait
		 (.oe(tmpOE__Compare_wait_net),
		  .y({Net_3003}),
		  .fb({tmpFB_0__Compare_wait_net[0:0]}),
		  .io({tmpIO_0__Compare_wait_net[0:0]}),
		  .siovref(tmpSIOVREF__Compare_wait_net),
		  .interrupt({tmpINTERRUPT_0__Compare_wait_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Compare_wait_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__LED_net;
	wire [0:0] tmpFB_0__LED_net;
	wire [0:0] tmpIO_0__LED_net;
	wire [0:0] tmpINTERRUPT_0__LED_net;
	electrical [0:0] tmpSIOVREF__LED_net;

	cy_psoc3_pins_v1_10
		#(.id("abd792cd-0028-4b44-a2bf-84ea41c827e9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		LED
		 (.oe(tmpOE__LED_net),
		  .y({Net_10805}),
		  .fb({tmpFB_0__LED_net[0:0]}),
		  .io({tmpIO_0__LED_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_net),
		  .interrupt({tmpINTERRUPT_0__LED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_80 LED_ON (
        .control_1(Net_10802),
        .control_2(Net_10803),
        .control_3(Net_10804),
        .control_0(Net_10805),
        .control_4(Net_10806),
        .control_5(Net_10807),
        .control_6(Net_10808),
        .control_7(Net_10809),
        .clock(1'b0),
        .reset(1'b0));
    defparam LED_ON.Bit0Mode = 0;
    defparam LED_ON.Bit1Mode = 0;
    defparam LED_ON.Bit2Mode = 0;
    defparam LED_ON.Bit3Mode = 0;
    defparam LED_ON.Bit4Mode = 0;
    defparam LED_ON.Bit5Mode = 0;
    defparam LED_ON.Bit6Mode = 0;
    defparam LED_ON.Bit7Mode = 0;
    defparam LED_ON.BitValue = 0;
    defparam LED_ON.BusDisplay = 0;
    defparam LED_ON.ExtrReset = 0;
    defparam LED_ON.NumOutputs = 1;


	cy_isr_v1_0
		#(.int_type(2'b00))
		EndFrame
		 (.int_signal(Net_10779));


    CyStatusReg_v1_90 StartButton_1 (
        .status_0(Net_11125),
        .status_1(1'b0),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Net_11118),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_11123),
        .status_bus(8'b0));
    defparam StartButton_1.Bit0Mode = 0;
    defparam StartButton_1.Bit1Mode = 0;
    defparam StartButton_1.Bit2Mode = 0;
    defparam StartButton_1.Bit3Mode = 0;
    defparam StartButton_1.Bit4Mode = 0;
    defparam StartButton_1.Bit5Mode = 0;
    defparam StartButton_1.Bit6Mode = 0;
    defparam StartButton_1.Bit7Mode = 0;
    defparam StartButton_1.BusDisplay = 0;
    defparam StartButton_1.Interrupt = 0;
    defparam StartButton_1.MaskValue = 0;
    defparam StartButton_1.NumInputs = 1;


    assign Net_10720 = ~Net_11008;


    assign Net_11008 = Net_1037 & Net_1453;

    assign Net_11118 = 1'h0;


    assign Net_11125 = ~Frame_clear[1];

    ShiftReg_v2_30_9 Period (
        .shift_in(Net_10925),
        .load(Net_11303),
        .store(1'b0),
        .clock(Net_677),
        .reset(1'b0),
        .shift_out(Net_11393),
        .interrupt(Net_11312));
    defparam Period.Direction = 1;
    defparam Period.FifoSize = 4;
    defparam Period.Length = 8;

    ShiftReg_v2_30_10 SigmaReg (
        .shift_in(Net_10946),
        .load(1'b0),
        .store(1'b0),
        .clock(Net_677),
        .reset(1'b0),
        .shift_out(Net_698),
        .interrupt(Net_11134));
    defparam SigmaReg.Direction = 1;
    defparam SigmaReg.FifoSize = 4;
    defparam SigmaReg.Length = 8;

    // -- LUT Sigma start --
    if (1)
    begin : Sigma
        reg [1:0] tmp__Sigma_reg;
        wire [2:0] tmp__Sigma_ins;
        assign tmp__Sigma_ins = {Net_686,Net_698,Net_11393};
        always @(posedge Net_819)
        begin
            case (tmp__Sigma_ins)
                3'b000 :  tmp__Sigma_reg = 2'b00;
                3'b001 :  tmp__Sigma_reg = 2'b01;
                3'b010 :  tmp__Sigma_reg = 2'b01;
                3'b011 :  tmp__Sigma_reg = 2'b10;
                3'b100 :  tmp__Sigma_reg = 2'b01;
                3'b101 :  tmp__Sigma_reg = 2'b10;
                3'b110 :  tmp__Sigma_reg = 2'b10;
                3'b111 :  tmp__Sigma_reg = 2'b11;
            endcase
        end
        assign {Net_686,Net_10946} = tmp__Sigma_reg;
    end
    // -- LUT Sigma end --

    // -- DFF Start --
    reg  cydff_9;
    always @(posedge Net_11403)
    begin
        cydff_9 <= Net_686;
    end
    assign Mhz4_096 = cydff_9;
    // -- DFF End --

    // -- DFF Start --
    reg  cydff_10;
    always @(posedge Net_11246)
    begin
        cydff_10 <= Net_860;
    end
    assign Net_11303 = cydff_10;
    // -- DFF End --

    CyControlReg_v1_80 Control_Period (
        .control_1(Net_11143),
        .control_2(Net_11144),
        .control_3(Net_11145),
        .control_0(Net_860),
        .control_4(Net_11146),
        .control_5(Net_11147),
        .control_6(Net_11148),
        .control_7(Net_11149),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Period.Bit0Mode = 0;
    defparam Control_Period.Bit1Mode = 0;
    defparam Control_Period.Bit2Mode = 0;
    defparam Control_Period.Bit3Mode = 0;
    defparam Control_Period.Bit4Mode = 0;
    defparam Control_Period.Bit5Mode = 0;
    defparam Control_Period.Bit6Mode = 0;
    defparam Control_Period.Bit7Mode = 0;
    defparam Control_Period.BitValue = 0;
    defparam Control_Period.BusDisplay = 0;
    defparam Control_Period.ExtrReset = 0;
    defparam Control_Period.NumOutputs = 1;

    Counter_v3_0_11 usec_counter (
        .reset(1'b0),
        .tc(Net_11068),
        .comp(Net_11207),
        .clock(Net_819),
        .interrupt(Net_11018),
        .enable(1'b0),
        .capture(Net_11269),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Mhz4_096));
    defparam usec_counter.CaptureMode = 1;
    defparam usec_counter.ClockMode = 0;
    defparam usec_counter.CompareMode = 0;
    defparam usec_counter.CompareStatusEdgeSense = 1;
    defparam usec_counter.EnableMode = 0;
    defparam usec_counter.ReloadOnCapture = 0;
    defparam usec_counter.ReloadOnCompare = 0;
    defparam usec_counter.ReloadOnOverUnder = 1;
    defparam usec_counter.ReloadOnReset = 0;
    defparam usec_counter.Resolution = 16;
    defparam usec_counter.RunMode = 0;
    defparam usec_counter.UseInterrupt = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		cap_comp_tc
		 (.int_signal(Net_11018));


    Counter_v3_0_12 Boundary8bit (
        .reset(1'b0),
        .tc(Net_11246),
        .comp(Net_11256),
        .clock(Net_819),
        .interrupt(Net_11257),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Boundary8bit.CaptureMode = 0;
    defparam Boundary8bit.ClockMode = 0;
    defparam Boundary8bit.CompareMode = 1;
    defparam Boundary8bit.CompareStatusEdgeSense = 1;
    defparam Boundary8bit.EnableMode = 0;
    defparam Boundary8bit.ReloadOnCapture = 0;
    defparam Boundary8bit.ReloadOnCompare = 0;
    defparam Boundary8bit.ReloadOnOverUnder = 1;
    defparam Boundary8bit.ReloadOnReset = 1;
    defparam Boundary8bit.Resolution = 8;
    defparam Boundary8bit.RunMode = 0;
    defparam Boundary8bit.UseInterrupt = 1;


    assign Net_677 = ~Net_819;


	cy_clock_v1_0
		#(.id("fc4436e9-87a7-46fb-ac68-45995e9db523"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		MC
		 (.clock_out(Net_819));


    CyControlReg_v1_80 Control_Capture (
        .control_1(Net_11175),
        .control_2(Net_11176),
        .control_3(Net_11177),
        .control_0(Net_11310),
        .control_4(Net_11178),
        .control_5(Net_11179),
        .control_6(Net_11180),
        .control_7(Net_11181),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Capture.Bit0Mode = 0;
    defparam Control_Capture.Bit1Mode = 0;
    defparam Control_Capture.Bit2Mode = 0;
    defparam Control_Capture.Bit3Mode = 0;
    defparam Control_Capture.Bit4Mode = 0;
    defparam Control_Capture.Bit5Mode = 0;
    defparam Control_Capture.Bit6Mode = 0;
    defparam Control_Capture.Bit7Mode = 0;
    defparam Control_Capture.BitValue = 1;
    defparam Control_Capture.BusDisplay = 0;
    defparam Control_Capture.ExtrReset = 0;
    defparam Control_Capture.NumOutputs = 1;

    // -- DFF Start --
    reg  cydff_15;
    always @(posedge Net_11310 or posedge Net_11184)
    begin
        if (Net_11310)
        begin
            cydff_15 <= 0;
        end
        else
        begin
            cydff_15 <= Net_11009;
        end
    end
    assign Net_11269 = cydff_15;
    // -- DFF End --

    assign Net_11009 = 1'h1;

	wire [0:0] tmpOE__Start_frame_net;
	wire [0:0] tmpIO_0__Start_frame_net;
	wire [0:0] tmpINTERRUPT_0__Start_frame_net;
	electrical [0:0] tmpSIOVREF__Start_frame_net;

	cy_psoc3_pins_v1_10
		#(.id("f2a97f0b-6372-4677-a201-e98e3f3f6a83"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Start_frame
		 (.oe(tmpOE__Start_frame_net),
		  .y({1'b0}),
		  .fb({Net_11184}),
		  .io({tmpIO_0__Start_frame_net[0:0]}),
		  .siovref(tmpSIOVREF__Start_frame_net),
		  .interrupt({tmpINTERRUPT_0__Start_frame_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Start_frame_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__TC_word_net;
	wire [0:0] tmpFB_0__TC_word_net;
	wire [0:0] tmpIO_0__TC_word_net;
	wire [0:0] tmpINTERRUPT_0__TC_word_net;
	electrical [0:0] tmpSIOVREF__TC_word_net;

	cy_psoc3_pins_v1_10
		#(.id("4f4c9b24-2e23-45a0-9050-11bf0f6b0a8a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		TC_word
		 (.oe(tmpOE__TC_word_net),
		  .y({Net_11246}),
		  .fb({tmpFB_0__TC_word_net[0:0]}),
		  .io({tmpIO_0__TC_word_net[0:0]}),
		  .siovref(tmpSIOVREF__TC_word_net),
		  .interrupt({tmpINTERRUPT_0__TC_word_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__TC_word_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Out_TikTak_net;
	wire [0:0] tmpFB_0__Out_TikTak_net;
	wire [0:0] tmpIO_0__Out_TikTak_net;
	wire [0:0] tmpINTERRUPT_0__Out_TikTak_net;
	electrical [0:0] tmpSIOVREF__Out_TikTak_net;

	cy_psoc3_pins_v1_10
		#(.id("733fd33f-9bf8-4fb4-a4d2-bfe695ba0761"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Out_TikTak
		 (.oe(tmpOE__Out_TikTak_net),
		  .y({Net_11292}),
		  .fb({tmpFB_0__Out_TikTak_net[0:0]}),
		  .io({tmpIO_0__Out_TikTak_net[0:0]}),
		  .siovref(tmpSIOVREF__Out_TikTak_net),
		  .interrupt({tmpINTERRUPT_0__Out_TikTak_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Out_TikTak_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- DFF Start --
    reg  cydff_7;
    always @(posedge Mhz4_096)
    begin
        cydff_7 <= Net_11293;
    end
    assign Net_11292 = cydff_7;
    // -- DFF End --

    CyStatusReg_v1_90 Status_Period (
        .status_0(Net_11303),
        .status_1(1'b0),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Net_11188),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_11193),
        .status_bus(8'b0));
    defparam Status_Period.Bit0Mode = 0;
    defparam Status_Period.Bit1Mode = 0;
    defparam Status_Period.Bit2Mode = 0;
    defparam Status_Period.Bit3Mode = 0;
    defparam Status_Period.Bit4Mode = 0;
    defparam Status_Period.Bit5Mode = 0;
    defparam Status_Period.Bit6Mode = 0;
    defparam Status_Period.Bit7Mode = 0;
    defparam Status_Period.BusDisplay = 0;
    defparam Status_Period.Interrupt = 0;
    defparam Status_Period.MaskValue = 0;
    defparam Status_Period.NumInputs = 1;

    assign Net_11188 = 1'h1;

    // -- DFF Start --
    reg  cydff_4;
    always @(posedge Net_819)
    begin
        cydff_4 <= Net_11393;
    end
    assign Net_10925 = cydff_4;
    // -- DFF End --


    assign Net_11244 = Net_11246 & Net_677;


    assign Net_11403 = ~Net_11244;


    assign Net_11293 = ~Net_11292;

	wire [0:0] tmpOE__Out_TikTak_1_net;
	wire [0:0] tmpFB_0__Out_TikTak_1_net;
	wire [0:0] tmpIO_0__Out_TikTak_1_net;
	wire [0:0] tmpINTERRUPT_0__Out_TikTak_1_net;
	electrical [0:0] tmpSIOVREF__Out_TikTak_1_net;

	cy_psoc3_pins_v1_10
		#(.id("b0980022-674f-46fd-bb0a-4f1982b54581"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Out_TikTak_1
		 (.oe(tmpOE__Out_TikTak_1_net),
		  .y({Net_11068}),
		  .fb({tmpFB_0__Out_TikTak_1_net[0:0]}),
		  .io({tmpIO_0__Out_TikTak_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Out_TikTak_1_net),
		  .interrupt({tmpINTERRUPT_0__Out_TikTak_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Out_TikTak_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

