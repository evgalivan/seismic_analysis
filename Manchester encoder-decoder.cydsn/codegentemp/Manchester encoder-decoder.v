// ======================================================================
// Manchester encoder-decoder.v generated from TopDesign.cysch
// 03/11/2020 at 15:51
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

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, DefSi=1, Direction=0, FifoSize=4, InterruptSource=1, Length=32, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, UseInputFifo=true, UseInterrupt=true, UseOutputFifo=false, UseShiftIn=false, UseShiftOut=true, VerilogSectionReplacementString=sC32, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=TransmitShiftReg, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=TransmitShiftReg, CY_INSTANCE_SHORT_NAME=TransmitShiftReg, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=TransmitShiftReg, )
module ShiftReg_v2_30_0 (
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

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=4, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=31, CONTROL3=0, ControlRegRemoved=1, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=1, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=true, InterruptOnTC=false, Period=32, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=false, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=BitCounterEnc, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=BitCounterEnc, CY_INSTANCE_SHORT_NAME=BitCounterEnc, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=BitCounterEnc, )
module Counter_v3_0_1 (
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

// Counter_v3_0(CaptureMode=1, CaptureModeSoftware=0, ClockMode=0, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=512, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG24, CySetRegReplacementString=CY_SET_REG24, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=true, InterruptOnCompare=true, InterruptOnOverUnderFlow=true, InterruptOnTC=false, Period=16777214, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=false, ReloadOnReset=false, Resolution=24, RunMode=0, UDB16=false, UDB24=true, UDB32=false, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC24, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=usec_counter, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=usec_counter, CY_INSTANCE_SHORT_NAME=usec_counter, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=usec_counter, )
module Counter_v3_0_2 (
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
    parameter ReloadOnOverUnder = 0;
    parameter ReloadOnReset = 0;
    parameter Resolution = 24;
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
    defparam CounterUDB.ReloadOnOverUnder = 0;
    defparam CounterUDB.ReloadOnReset = 0;
    defparam CounterUDB.Resolution = 24;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



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

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, DefSi=0, Direction=1, FifoSize=4, InterruptSource=0, Length=32, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, UseInputFifo=false, UseInterrupt=false, UseOutputFifo=false, UseShiftIn=true, UseShiftOut=true, VerilogSectionReplacementString=sC32, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=SigmaReg, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SigmaReg, CY_INSTANCE_SHORT_NAME=SigmaReg, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=SigmaReg, )
module ShiftReg_v2_30_3 (
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
    defparam bSR.Direction = 1;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 0;
    defparam bSR.Length = 32;
    defparam bSR.UseInputFifo = 0;
    defparam bSR.UseInterrupt = 0;
    defparam bSR.UseOutputFifo = 0;



endmodule

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, DefSi=0, Direction=1, FifoSize=4, InterruptSource=1, Length=32, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, UseInputFifo=true, UseInterrupt=false, UseOutputFifo=false, UseShiftIn=true, UseShiftOut=true, VerilogSectionReplacementString=sC32, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONFIG_TITLE=Period, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Period, CY_INSTANCE_SHORT_NAME=Period, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Period, )
module ShiftReg_v2_30_4 (
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
    defparam bSR.Direction = 1;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 1;
    defparam bSR.Length = 32;
    defparam bSR.UseInputFifo = 1;
    defparam bSR.UseInterrupt = 0;
    defparam bSR.UseOutputFifo = 0;



endmodule

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=3, CONTROL3=1, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FF16=false, FF8=true, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=31, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=Boundary32bit, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Boundary32bit, CY_INSTANCE_SHORT_NAME=Boundary32bit, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=Boundary32bit, )
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

// Counter_v3_0(CaptureMode=1, CaptureModeSoftware=0, ClockMode=0, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=128, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG32, CySetRegReplacementString=CY_SET_REG32, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=0, InterruptOnCapture=true, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=4294967294, RegDefReplacementString=reg32, RegSizeReplacementString=uint32, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=false, ReloadOnReset=false, Resolution=32, RunMode=0, UDB16=false, UDB24=false, UDB32=true, UDB8=false, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC32, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Counter_v3_0, CY_CONFIG_TITLE=sec_counter, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=sec_counter, CY_INSTANCE_SHORT_NAME=sec_counter, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=sec_counter, )
module Counter_v3_0_6 (
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
    parameter ReloadOnOverUnder = 0;
    parameter ReloadOnReset = 0;
    parameter Resolution = 32;
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
    defparam CounterUDB.ReloadOnOverUnder = 0;
    defparam CounterUDB.ReloadOnReset = 0;
    defparam CounterUDB.Resolution = 32;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: B_UART_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`endif

// UART_v2_50(Address1=0, Address2=0, BaudRate=9600, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=false, InternalClock=true, InternalClockToleranceMinus=3.93736842105263, InternalClockTolerancePlus=3.93736842105263, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=76800, RXAddressMode=0, RXBufferSize=4, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=4, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=UART_v2_50, CY_CONFIG_TITLE=UART, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=UART, )
module UART_v2_50_7 (
    cts_n,
    tx,
    rts_n,
    tx_en,
    clock,
    reset,
    rx,
    tx_interrupt,
    rx_interrupt,
    tx_data,
    tx_clk,
    rx_data,
    rx_clk);
    input       cts_n;
    output      tx;
    output      rts_n;
    output      tx_en;
    input       clock;
    input       reset;
    input       rx;
    output      tx_interrupt;
    output      rx_interrupt;
    output      tx_data;
    output      tx_clk;
    output      rx_data;
    output      rx_clk;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 0;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("13020833333.3333"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_50 BUART (
        .cts_n(cts_n),
        .tx(tx),
        .rts_n(rts_n),
        .tx_en(tx_en),
        .clock(Net_61),
        .reset(reset),
        .rx(rx),
        .tx_interrupt(tx_interrupt),
        .rx_interrupt(rx_interrupt),
        .tx_data(tx_data),
        .tx_clk(tx_clk),
        .rx_data(rx_data),
        .rx_clk(rx_clk));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 0;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 1;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 1;



endmodule

// top
module top ;

          wire  Net_11419;
          wire  Net_11418;
          wire  Net_11417;
          wire  Net_11416;
          wire  Net_11415;
          wire  Net_11414;
          wire  Net_11413;
          wire  Net_11412;
          wire  Net_11411;
          wire  Net_11410;
          wire  Net_11409;
          wire  Net_11408;
          wire  Net_11407;
          wire [7:0] Net_11392;
          wire  Net_11391;
          wire  Net_11390;
          wire  Net_11389;
          wire  Net_11388;
          wire  Net_11387;
          wire  Net_11386;
          wire  Net_11385;
          wire  Net_11384;
          wire  Net_11383;
          wire  Net_11230;
          wire  Net_11229;
          wire  Net_11228;
          wire  Net_11227;
          wire  Net_11226;
          wire  Net_11225;
          wire  Net_11224;
          wire  Net_11223;
          wire  Net_11245;
          wire  Net_11244;
          wire  Net_11243;
          wire  Net_11242;
          wire  Net_11241;
          wire  Net_11240;
          wire  Net_11239;
          wire  S;
          wire  Net_11237;
          wire  Net_11235;
          wire  Net_11173;
          wire  Net_11172;
          wire  Net_11171;
          wire  Net_11272;
          wire  Net_11174;
          wire [2:0] preouts;
          wire [2:0] My_wire;
          wire  Net_10830;
          wire  Net_10910;
          wire  Net_11182;
          wire  Net_11181;
          wire  Net_11180;
          wire  Net_11179;
          wire  Net_11178;
          wire  Net_11177;
          wire  Net_11176;
          wire  Net_11175;
          wire  Net_11267;
          wire  Net_11326;
          wire  Net_11325;
          wire  Net_11324;
          wire  Net_11323;
          wire  Net_11322;
          wire  Net_11321;
          wire  Net_11320;
          wire  Net_11319;
          wire  Net_914;
          wire  Net_11283;
          wire  Net_11281;
          wire  Net_11280;
          wire  Net_11279;
          wire  Net_11278;
          wire  Net_11277;
          wire  Net_11276;
          wire  Net_11275;
          wire  Net_11274;
          wire  Net_11273;
          wire  Net_11211;
          wire  Net_11210;
          wire  Net_11209;
          wire  Net_11208;
          wire  Net_11206;
          wire  Net_11008;
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
          wire  Net_10552;
          wire  Net_10551;
    electrical  Net_10561;
    electrical  Net_10562;
          wire  Net_10554;
          wire  Net_10691;
          wire  Net_10690;
          wire  Net_10689;
          wire  Net_10260;
          wire  Net_10827;
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
          wire  Net_11403;
          wire  Net_853;
          wire  Net_11406;
          wire  Net_11068;
          wire  Net_11207;
          wire  Net_11310;
          wire  Net_11269;
          wire  Net_10946;
          wire  Net_686;
          wire  Net_860;
          wire  Net_10916;
          wire  Net_11009;
          wire  Net_11018;
          wire  Net_698;
          wire  Net_867;
          wire  Net_819;
          wire  Net_10925;
          wire  Net_677;
          wire  Net_11393;
          wire  Net_9581;
          wire  Net_10720;
          wire  Net_1453;
          wire  Net_10896;
          wire  Net_1037;
          wire  Net_10805;
          wire  Net_10511;
          wire  Net_10746;
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
          wire  Net_3360;
          wire  Net_2241;

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

    ShiftReg_v2_30_0 TransmitShiftReg (
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

    // -- DFF Start --
    reg  cydff_1;
    always @(posedge Net_819)
    begin
        cydff_1 <= Net_11393;
    end
    assign Net_10925 = cydff_1;
    // -- DFF End --

    Counter_v3_0_1 BitCounterEnc (
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


    assign Net_10720 = ~Net_11008;


    assign Net_11008 = Net_1037 & Net_1453;


	cy_isr_v1_0
		#(.int_type(2'b10))
		cap_comp_tc
		 (.int_signal(Net_11018));


    Counter_v3_0_2 usec_counter (
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
        .count(Net_11406));
    defparam usec_counter.CaptureMode = 1;
    defparam usec_counter.ClockMode = 0;
    defparam usec_counter.CompareMode = 0;
    defparam usec_counter.CompareStatusEdgeSense = 1;
    defparam usec_counter.EnableMode = 0;
    defparam usec_counter.ReloadOnCapture = 0;
    defparam usec_counter.ReloadOnCompare = 0;
    defparam usec_counter.ReloadOnOverUnder = 0;
    defparam usec_counter.ReloadOnReset = 0;
    defparam usec_counter.Resolution = 24;
    defparam usec_counter.RunMode = 0;
    defparam usec_counter.UseInterrupt = 1;

    CyControlReg_v1_80 Control_Capture (
        .control_1(Net_11273),
        .control_2(Net_11274),
        .control_3(Net_11275),
        .control_0(Net_11310),
        .control_4(Net_11276),
        .control_5(Net_11277),
        .control_6(Net_11278),
        .control_7(Net_11279),
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
    always @(posedge Net_11310 or posedge Net_11283)
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

	wire [0:0] tmpOE__PPS_net;
	wire [0:0] tmpIO_0__PPS_net;
	wire [0:0] tmpINTERRUPT_0__PPS_net;
	electrical [0:0] tmpSIOVREF__PPS_net;

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
		PPS
		 (.oe(tmpOE__PPS_net),
		  .y({1'b0}),
		  .fb({Net_11283}),
		  .io({tmpIO_0__PPS_net[0:0]}),
		  .siovref(tmpSIOVREF__PPS_net),
		  .interrupt({tmpINTERRUPT_0__PPS_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PPS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_80 Control_Period (
        .control_1(Net_914),
        .control_2(Net_11319),
        .control_3(Net_11320),
        .control_0(Net_860),
        .control_4(Net_11321),
        .control_5(Net_11322),
        .control_6(Net_11323),
        .control_7(Net_11324),
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

    // -- DFF Start --
    reg  cydff_10;
    always @(posedge Net_867)
    begin
        cydff_10 <= Net_860;
    end
    assign Net_10916 = cydff_10;
    // -- DFF End --


    assign Net_853 = Net_867 & Net_677;

    // -- DFF Start --
    reg  cydff_9;
    always @(posedge Net_11403)
    begin
        cydff_9 <= Net_686;
    end
    assign Net_11406 = cydff_9;
    // -- DFF End --

	wire [0:0] tmpOE__Clock_tiktak_net;
	wire [0:0] tmpFB_0__Clock_tiktak_net;
	wire [0:0] tmpIO_0__Clock_tiktak_net;
	wire [0:0] tmpINTERRUPT_0__Clock_tiktak_net;
	electrical [0:0] tmpSIOVREF__Clock_tiktak_net;

	cy_psoc3_pins_v1_10
		#(.id("235e8817-8b61-4bc8-967e-71ac7bc002d0"),
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
		Clock_tiktak
		 (.oe(tmpOE__Clock_tiktak_net),
		  .y({Net_11406}),
		  .fb({tmpFB_0__Clock_tiktak_net[0:0]}),
		  .io({tmpIO_0__Clock_tiktak_net[0:0]}),
		  .siovref(tmpSIOVREF__Clock_tiktak_net),
		  .interrupt({tmpINTERRUPT_0__Clock_tiktak_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Clock_tiktak_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("fc4436e9-87a7-46fb-ac68-45995e9db523"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		MC
		 (.clock_out(Net_819));



    assign Net_677 = ~Net_819;

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

    ShiftReg_v2_30_3 SigmaReg (
        .shift_in(Net_10946),
        .load(1'b0),
        .store(1'b0),
        .clock(Net_677),
        .reset(1'b0),
        .shift_out(Net_698),
        .interrupt(Net_11272));
    defparam SigmaReg.Direction = 1;
    defparam SigmaReg.FifoSize = 4;
    defparam SigmaReg.Length = 32;

    ShiftReg_v2_30_4 Period (
        .shift_in(Net_10925),
        .load(Net_10916),
        .store(1'b0),
        .clock(Net_677),
        .reset(1'b0),
        .shift_out(Net_11393),
        .interrupt(Net_11173));
    defparam Period.Direction = 1;
    defparam Period.FifoSize = 4;
    defparam Period.Length = 32;

    Counter_v3_0_5 Boundary32bit (
        .reset(1'b0),
        .tc(Net_867),
        .comp(Net_11237),
        .clock(Net_819),
        .interrupt(Net_11239),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Boundary32bit.CaptureMode = 0;
    defparam Boundary32bit.ClockMode = 0;
    defparam Boundary32bit.CompareMode = 1;
    defparam Boundary32bit.CompareStatusEdgeSense = 1;
    defparam Boundary32bit.EnableMode = 0;
    defparam Boundary32bit.ReloadOnCapture = 0;
    defparam Boundary32bit.ReloadOnCompare = 0;
    defparam Boundary32bit.ReloadOnOverUnder = 1;
    defparam Boundary32bit.ReloadOnReset = 1;
    defparam Boundary32bit.Resolution = 8;
    defparam Boundary32bit.RunMode = 0;
    defparam Boundary32bit.UseInterrupt = 1;

    Counter_v3_0_6 sec_counter (
        .reset(1'b0),
        .tc(Net_11224),
        .comp(Net_11225),
        .clock(Net_819),
        .interrupt(Net_11226),
        .enable(1'b0),
        .capture(Net_11269),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Net_11068));
    defparam sec_counter.CaptureMode = 1;
    defparam sec_counter.ClockMode = 0;
    defparam sec_counter.CompareMode = 0;
    defparam sec_counter.CompareStatusEdgeSense = 1;
    defparam sec_counter.EnableMode = 0;
    defparam sec_counter.ReloadOnCapture = 0;
    defparam sec_counter.ReloadOnCompare = 0;
    defparam sec_counter.ReloadOnOverUnder = 0;
    defparam sec_counter.ReloadOnReset = 0;
    defparam sec_counter.Resolution = 32;
    defparam sec_counter.RunMode = 0;
    defparam sec_counter.UseInterrupt = 1;

    CyStatusReg_v1_90 Status_Period (
        .status_0(Net_10916),
        .status_1(1'b0),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Net_11386),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_11391),
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
		  .y({Net_11207}),
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
		  .y({Net_867}),
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

    assign Net_11386 = 1'h1;


    assign Net_11403 = ~Net_853;

    UART_v2_50_7 UART (
        .cts_n(1'b0),
        .tx(Net_11408),
        .rts_n(Net_11409),
        .tx_en(Net_11410),
        .clock(1'b0),
        .reset(1'b0),
        .rx(Net_11413),
        .tx_interrupt(Net_11414),
        .rx_interrupt(Net_11415),
        .tx_data(Net_11416),
        .tx_clk(Net_11417),
        .rx_data(Net_11418),
        .rx_clk(Net_11419));
    defparam UART.Address1 = 0;
    defparam UART.Address2 = 0;
    defparam UART.EnIntRXInterrupt = 0;
    defparam UART.EnIntTXInterrupt = 0;
    defparam UART.FlowControl = 0;
    defparam UART.HalfDuplexEn = 0;
    defparam UART.HwTXEnSignal = 0;
    defparam UART.NumDataBits = 8;
    defparam UART.NumStopBits = 1;
    defparam UART.ParityType = 0;
    defparam UART.RXEnable = 1;
    defparam UART.TXEnable = 1;

	wire [0:0] tmpOE__Rx_1_net;
	wire [0:0] tmpIO_0__Rx_1_net;
	wire [0:0] tmpINTERRUPT_0__Rx_1_net;
	electrical [0:0] tmpSIOVREF__Rx_1_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
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
		Rx_1
		 (.oe(tmpOE__Rx_1_net),
		  .y({1'b0}),
		  .fb({Net_11413}),
		  .io({tmpIO_0__Rx_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Rx_1_net),
		  .interrupt({tmpINTERRUPT_0__Rx_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Rx_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Tx_1_net;
	wire [0:0] tmpFB_0__Tx_1_net;
	wire [0:0] tmpIO_0__Tx_1_net;
	wire [0:0] tmpINTERRUPT_0__Tx_1_net;
	electrical [0:0] tmpSIOVREF__Tx_1_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
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
		Tx_1
		 (.oe(tmpOE__Tx_1_net),
		  .y({Net_11408}),
		  .fb({tmpFB_0__Tx_1_net[0:0]}),
		  .io({tmpIO_0__Tx_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Tx_1_net),
		  .interrupt({tmpINTERRUPT_0__Tx_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Tx_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_rx
		 (.int_signal(Net_11415));




endmodule

