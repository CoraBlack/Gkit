use std::os::raw::c_int;

#[no_mangle]
#[allow(non_snake_case)]
extern "C" fn R_Print_Hello() -> c_int {
    println!("Hello from Rust!");
    return 0;
}