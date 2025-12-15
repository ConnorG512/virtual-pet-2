{
  description = "Virtual pet 2 flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 
  let 
    pkgs = nixpkgs.legacyPackages.x86_64-linux;
  in
  {
    devShells.x86_64-linux.default = pkgs.mkShell {
      packages = with pkgs; [
      ccls
      cmake
      ninja
      
      mesa
      libGL
      
      sdl3

      strace 
      gef
      renderdoc
    ];
    
    LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
      pkgs.libGL
      pkgs.mesa
      pkgs.renderdoc
    ];

    shellHook = ''
      echo "Entering virtual pet 2 shell!"
    '';
    };
  };
}
