use tauri::{CustomMenuItem};

pub struct MenuItems {
    pub close: CustomMenuItem,
    pub quit: CustomMenuItem,

    pub starter_number: CustomMenuItem,
    pub mode: CustomMenuItem,
    pub ascii: CustomMenuItem,

    pub random_theme: CustomMenuItem,
}

pub struct Settings {
    pub starter_number: i128,
    pub mode: i32,
    pub ascii: bool,
}