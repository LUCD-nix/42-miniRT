Engine:

    - [ ] Consider using the analytical gradients for shading normals
    https://iquilezles.org/articles/distgradfunctions3d/
    (sphere & cylinder available);
    - [ ] consider updating lerp to be better;
    - [ ] fix weird colour on cube in demo
    - [ ] fix cylinder - sphere unsmooth being just a hole

Done/abandoned:

    - [x] Start work on smooth shading, using raymarching
        - https://iquilezles.org/articles/rmshadows/
    - [x] Implement a camera struct and make get_uv use it;
    - [x] Rewrite parts of rendering to support colours (sdfs/combining should return tuple of distance + colour)
        and so should the combining (lerp if smoothing)
    - [x] GET THIS GODDAMN THING TO COMPILE
    - [x] i don't thing it's the libraries but do check (go to file) if we have libext
    - [x] im almost certain it's the std=gnu99 that's messing it up but doing that fixes the
    other compiler error so idk man
    - [x] Make SDFs always use origin
        - [x] implies implementing a way to translate and rotate space
        which would have to be used at sdf call site
            - might need determinant soon.
    - [x] Added simple colour lerping
    - [x] Install perf to see the hot loops in the code
    - [x] refactor drawing funcs in their own module;
    - [x] Start work on sdf call structure
        - [x] So the choice is a static array of structs or a static structure
        of arrays;
            - [x] second option means shapes.h refactor
