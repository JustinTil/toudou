pub mod parser {
    #[allow(unused)]
    use std::path::PathBuf;
    #[allow(unused)]
    use clap::Parser;
    
    #[derive(Parser)]
    #[derive(Debug)]
    #[command(author, version, about, long_about = None)]
    pub struct Cli {
        /// Add a task to the list 
        #[arg(short = 'a', long = "add")]
        pub add_flag: Option<String>,
        
        /// Remove a task from the list
        #[arg(short = 'r', long = "remove")]
        pub remove_flag: Option<usize>,
    }  
}

use clap::Parser;
pub fn get_args() -> parser::Cli {
        parser::Cli::parse()
    }
