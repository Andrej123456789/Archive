#![allow(unused)]

use rand::Rng;

static mut STARTUP: bool = true;

// Functions which can be accessed from frotend, JavaScript in our case

#[tauri::command]
pub fn random_theme() -> String {
    let mut theme_str = "";

    let mut rng = rand::thread_rng();
    let num: i32 = rng.gen_range(0..2);

    unsafe {
        if STARTUP == false {
            println!("[LOG]: New theme id is: {}", num);
        }

        else {
            STARTUP = false;
            return "".to_string().into();
        }
    }

    match num {
        0 => theme_str = "light",
        1 => theme_str = "dark",
        _ => theme_str = "",
    }

    println!("Theme is: {}", theme_str);

    return theme_str.to_string().into();
}

// Functions for main.rs

pub fn log(color: String, str: String) {
    // TODO: implement colors

    println!("[LOG]: {}", str);
}

// Functions for menu down below

pub fn quit() {
    std::process::exit(0);
}
