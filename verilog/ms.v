// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 07:09:45

`timescale 1ns/1ps 

module Top (
  input               a_valid,
  input      [7:0]    a_payload,
  output              b_valid,
  output     [7:0]    b_payload
);


  assign b_valid = a_valid;
  assign b_payload = a_payload;

endmodule
