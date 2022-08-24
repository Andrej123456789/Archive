#![cfg_attr(
    all(not(debug_assertions), target_os = "windows"),
    windows_subsystem = "windows"
)]

#![allow(unused)]

use tauri::{CustomMenuItem, Menu, MenuItem, Submenu};

mod functions;
mod vars;

fn main() {
    let menu_item = vars::MenuItems {
        close: CustomMenuItem::new("close", "Close"),
        quit: CustomMenuItem::new("quit", "Quit"),

        starter_number: CustomMenuItem::new("starter_number", "Set starter number"),
        mode: CustomMenuItem::new("mode", "Set mode"),
        ascii: CustomMenuItem::new("ascii", "Render with ASCII chars only"),

        random_theme: CustomMenuItem::new("random_theme", "Random theme"),
    };

    let options = vars::Settings {
        starter_number: 27,
        mode: 0,
        ascii: true,
    };

    println!("[LOG]: Default settings are: ");
    println!("              Number to visualize: {}", options.starter_number);
    println!("              Mode (1 - without showing max number, 2 - showing max number): {}", options.mode);
    println!("              Use only ASCII chars: {}", options.ascii);
    println!(" ");

    let main = Submenu::new("Main", Menu::new().add_item(menu_item.close).add_item(menu_item.quit));
    let set = Submenu::new("Set options", Menu::new().add_item(menu_item.starter_number).add_item(menu_item.mode).add_item(menu_item.ascii));
    let themes = Submenu::new("Themes", Menu::new().add_item(menu_item.random_theme));
    let menu = Menu::new()
        .add_native_item(MenuItem::Copy)
        .add_submenu(main)
        .add_submenu(set)
        .add_submenu(themes);

    tauri::Builder::default()
    .menu(menu)
    .on_menu_event(|event| {
        match event.menu_item_id() {
            "close" => {
                event.window().close().unwrap();
            }

            "quit" => {
                functions::quit();
            }

            "starter_number" => {

            }

            "mode" => {

            }

            "ascii" => {
                
            }

            "random_theme" => {
                let new_theme = functions::random_theme();
                let window = event.window();
                window.eval("['Theme']('dark')");
            }
            _ => {}
        }
      })
    .invoke_handler(tauri::generate_handler![functions::random_theme])
    .run(tauri::generate_context!())
    .expect("error while running tauri application");
}
