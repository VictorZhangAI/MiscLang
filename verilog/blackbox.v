// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 06:36:30

`timescale 1ns/1ps 

module Top (
  input               io_writeValid,
  input      [7:0]    io_writeAddress,
  input      [7:0]    io_writeData_r,
  input      [7:0]    io_writeData_g,
  input      [7:0]    io_writeData_b,
  input               io_readValid,
  input      [7:0]    io_readAddress,
  output     [7:0]    io_readData_r,
  output     [7:0]    io_readData_g,
  output     [7:0]    io_readData_b,
  input               clk
);

  wire                mem_wr_en;
  wire       [23:0]   mem_wr_data;
  wire                mem_rd_en;
  wire       [23:0]   mem_rd_data;
  wire       [23:0]   t_io_readData_r;

  Ram_1w_1rs #(
    .wordCount(1024),
    .wordWidth(24),
    .clockCrossing(1'b0),
    .technology("auto"),
    .readUnderWrite("dontCare"),
    .wrAddressWidth(8),
    .wrDataWidth(24),
    .wrMaskWidth(1),
    .wrMaskEnable(1'b0),
    .rdAddressWidth(8),
    .rdDataWidth(24) 
  ) mem (
    .wr_clk     (clk                   ), //i
    .wr_en      (mem_wr_en             ), //i
    .wr_mask    (1'b1                  ), //i
    .wr_addr    (io_writeAddress[7:0]  ), //i
    .wr_data    (mem_wr_data[23:0]     ), //i
    .rd_clk     (clk                   ), //i
    .rd_en      (mem_rd_en             ), //i
    .rd_addr    (io_readAddress[7:0]   ), //i
    .rd_data    (mem_rd_data[23:0]     )  //o
  );
  assign t_io_readData_r = mem_rd_data;
  assign io_readData_r = t_io_readData_r[7 : 0];
  assign io_readData_g = t_io_readData_r[15 : 8];
  assign io_readData_b = t_io_readData_r[23 : 16];
  assign mem_wr_en = (io_writeValid && 1'b1);
  assign mem_wr_data = {io_writeData_b,{io_writeData_g,io_writeData_r}};
  assign mem_rd_en = (io_readValid && 1'b1);

endmodule
