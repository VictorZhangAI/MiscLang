// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 06:27:56

`timescale 1ns/1ps 

module Top (
  input               io_writeValid,
  input      [7:0]    io_writeAddress,
  input      [31:0]   io_writeData,
  input               io_readValid,
  input      [7:0]    io_readAddress,
  output     [31:0]   io_readData,
  input               clk,
  input               resetn
);

  reg        [31:0]   t_mem_port1;
  reg [31:0] mem [0:255];

  always @(posedge clk) begin
    if(io_writeValid) begin
      mem[io_writeAddress] <= io_writeData;
    end
  end

  always @(posedge clk) begin
    if(io_readValid) begin
      t_mem_port1 <= mem[io_readAddress];
    end
  end

  assign io_readData = t_mem_port1;

endmodule
