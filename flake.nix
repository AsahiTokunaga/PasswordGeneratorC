{
  description = "A password generator made by C";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs?ref=release-24.11";
    flakeutils.url = "github:numtide/flake-utils";   
  };

  outputs = { self, nixpkgs, flakeutils }: 
    flakeutils.lib.eachDefaultSystem (system:
      let
        inherit (nixpkgs.lib) optional;
        pkgs = import nixpkgs { inherit system; };

        gcc = pkgs.libgcc;
        gdb = pkgs.gdb;
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = [
            gcc
            gdb
          ];
        };
      }
    );
}
