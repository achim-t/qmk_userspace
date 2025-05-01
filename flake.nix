{
  description = "Minimal Nix Flake Dev Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in {
        devShells.default = pkgs.mkShell {
          name = "my-dev-env";

          buildInputs = with pkgs; [
            git
            qmk
          ];

          shellHook = ''
            echo "🧊 Welcome to your Nix dev shell!"
          '';
        };
      });
}
