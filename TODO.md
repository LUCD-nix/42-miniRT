Engine:

    - [ ] Consider using the analytical gradients for shading normals
    https://iquilezles.org/articles/distgradfunctions3d/
    (sphere & cylinder available);
    - [x] Implement a camera struct and make get_uv use it;
    - [ ] Start work on smooth shading, using raymarching
        - https://iquilezles.org/articles/rmshadows/
    - [ ] Inigo has intersection functions, could be a performance hail
    mary if it gets too bad but could take a while to implement
    - [ ] Rewrite parts of rendering to support colours (sdfs/combining should return tuple of distance + colour)
        and so should the combining (lerp if smoothing)
    - [ ] consider updating lerp to be better;

Done/abandoned: 

    - [x] Make SDFs always use origin
        - [x] implies implementing a way to translate and rotate space
        which would have to be used at sdf call site
            - might need determinant soon.
    - [x] Added simple colour lerping
    - [w] Install perf to see the hot loops in the code
        - [x] needs bison
        - [x] needs flex
        - [ ] needs a bunch of libraries i am a bit lazy to fetch
            - [ ] also needs them in INCLUDES at runtime
    - [x] refactor drawing funcs in their own module;
    - [x] Start work on sdf call structure
        - [x] So the choice is a static array of structs or a static structure
        of arrays;
            - [x] second option means shapes.h refactor
