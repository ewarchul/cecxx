{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell rec {
    buildInputs = with pkgs; [
      cmake
      cmocka
      ninja
      gdb
      valgrind
    ];
  }
