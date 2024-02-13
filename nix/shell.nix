{ pkgs ? import <nixpkgs> {} }:

let
  cmake = pkgs.cmake;
in

pkgs.mkShell {
  name = "new_project";
  buildInputs = [
    pkgs.libpng
    pkgs.flex
    pkgs.bison
    cmake
    pkgs.gcc
  ];
}
