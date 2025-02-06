// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : InternalClockWithPllExample
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 06/02/2025, 06:39:41

`timescale 1ns/1ps 

module InternalClockWithPllExample (
  input               io_clk100M,
  input               io_aReset,
  output     [3:0]    io_result
);

  wire                pll_1_io_clkOut;
  wire                pll_1_io_reset;
  wire                myClockName_clk;
  wire                myClockName_resetn;
  reg        [3:0]    myArea_myReg;

  Pll pll_1 (
    .io_clkIn     (io_clk100M       ), //i
    .io_clkOut    (pll_1_io_clkOut  ), //o
    .io_reset     (pll_1_io_reset   )  //o
  );
  assign myClockName_clk = pll_1_io_clkOut;
  assign myClockName_resetn = (io_aReset || (! pll_1_io_reset));
  assign io_result = myArea_myReg;
  always @(posedge myClockName_clk or negedge myClockName_resetn) begin
    if(!myClockName_resetn) begin
      myArea_myReg <= 4'b0111;
    end else begin
      myArea_myReg <= (myArea_myReg + 4'b0001);
    end
  end


endmodule

module Pll (
  input               io_clkIn,
  output              io_clkOut,
  output              io_reset
);


  assign io_clkOut = io_clkIn;
  assign io_reset = 1'b0;

endmodule
