// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 03/02/2025, 06:39:20

`timescale 1ns/1ps 

module Top (
  input               clk,
  input               resetn
);

  wire                x;
  reg        [7:0]    y;
  reg                 x_regNext;
  wire                when_cmd5.sc_l4;

  assign when_cmd5.sc_l4 = (x ^ x_regNext);
  always @(*) begin
    if(when_cmd5.sc_l4) begin
      y = 8'hff;
    end else begin
      y = 8'h0;
    end
  end

  always @(posedge clk) begin
    x_regNext <= x;
  end


endmodule
