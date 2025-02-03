// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 03/02/2025, 08:00:50

`timescale 1ns/1ps 

module Top (
  input               clk,
  input               resetn
);

  wire                inc;
  wire                clear;
  reg        [7:0]    counter;

  always @(posedge clk) begin
    if(inc) begin
      counter <= (counter + 8'h01);
    end
    if(clear) begin
      counter <= 8'h0;
    end
  end


endmodule
