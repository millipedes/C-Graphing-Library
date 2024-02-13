{ pkgs ? import <nixpkgs> {} }:

let
  cmake = pkgs.cmake;
in

pkgs.mkShell {
  name = "new_project";
  buildInputs = [
    pkgs.libpng
    cmake
    pkgs.gcc
  ];
}
