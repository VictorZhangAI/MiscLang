// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : StreamFifo
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 06/02/2025, 07:30:48

`timescale 1ns/1ps 

module StreamFifo (
  input               io_push_valid,
  output reg          io_push_ready,
  input      [7:0]    io_push_payload,
  output              io_pop_valid,
  input               io_pop_ready,
  output     [7:0]    io_pop_payload,
  input               io_flush,
  output     [0:0]    io_occupancy,
  output     [0:0]    io_availability,
  input               clk,
  input               resetn
);

  wire                io_push_m2sPipe_valid;
  wire                io_push_m2sPipe_ready;
  wire       [7:0]    io_push_m2sPipe_payload;
  reg                 io_push_rValid;
  reg        [7:0]    io_push_rData;
  wire                when_Stream_l342;

  always @(*) begin
    io_push_ready = io_push_m2sPipe_ready;
    if(when_Stream_l342) begin
      io_push_ready = 1'b1;
    end
  end

  assign when_Stream_l342 = (! io_push_m2sPipe_valid);
  assign io_push_m2sPipe_valid = io_push_rValid;
  assign io_push_m2sPipe_payload = io_push_rData;
  assign io_pop_valid = io_push_m2sPipe_valid;
  assign io_push_m2sPipe_ready = io_pop_ready;
  assign io_pop_payload = io_push_m2sPipe_payload;
  assign io_occupancy = io_pop_valid;
  assign io_availability = (! io_pop_valid);
  always @(posedge clk or negedge resetn) begin
    if(!resetn) begin
      io_push_rValid <= 1'b0;
    end else begin
      if(io_push_ready) begin
        io_push_rValid <= io_push_valid;
      end
      if(io_flush) begin
        io_push_rValid <= 1'b0;
      end
    end
  end

  always @(posedge clk) begin
    if(io_push_ready) begin
      io_push_rData <= io_push_payload;
    end
  end


endmodule
