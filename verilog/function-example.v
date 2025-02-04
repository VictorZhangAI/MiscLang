// Generator : SpinalHDL v1.6.4    git head : 598c18959149eb18e5eee5b0aa3eef01ecaa41a1
// Component : Top
// Git hash  : 883e3261e1539ce4f27f302f74df8bec4bfaa77b
// Date      : 04/02/2025, 07:59:18

`timescale 1ns/1ps 

module Top (
  input      [7:0]    a,
  output     [7:0]    b,
  output     [7:0]    c
);

  wire       [7:0]    fix_1_b;

  Fix fix_1 (
    .a    (a[7:0]        ), //i
    .b    (fix_1_b[7:0]  )  //o
  );
  assign b = a;
  assign c = fix_1_b;

endmodule

module Fix (
  input      [7:0]    a,
  output     [7:0]    b
);


  assign b = a;

endmodule
