cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(minilibx_macos)

add_executable(fractol
        minilibx_macos/font.c
        minilibx_macos/mlx.h
        minilibx_macos/mlx_init_loop.m
        minilibx_macos/mlx_int.h
        minilibx_macos/mlx_int_str_to_wordtab.c
        minilibx_macos/mlx_new_image.m
        minilibx_macos/mlx_new_window.h
        minilibx_macos/mlx_new_window.m
        minilibx_macos/mlx_rgb.c
        minilibx_macos/mlx_shaders.c
        minilibx_macos/mlx_xpm.c
        fractal_zoom.c
        fractol.c
        fractol.h
        julia.c
        main.c
        mouse_move.c
        usage.c)
