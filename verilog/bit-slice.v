// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : T6
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 06:54:56

`timescale 1ns/1ps 

module T6 (
  input      [15:0]   a,
  output     [3:0]    b,
  output     [4:0]    c,
  output              o0,
  output              o1,
  output              o2,
  output              o3
);


  assign b = a[5 : 2];
  assign c = a[4 : 0];
  assign o0 = a[15];
  assign o1 = a[0];
  assign o2 = a[0];
  assign o3 = a[9];

endmodule
