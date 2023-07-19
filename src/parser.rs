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
        add_flag: Option<String>,
        
        /// Check a task when it is done
        #[arg(short = 'c', long = "check")]
        check_flag: Option<i8>,
        
        /// Remove a task from the list
        #[arg(short = 'r', long = "remove")]
        remove_flag: Option<i8>,
    }  
}

use clap::Parser;
pub fn get_args() -> parser::Cli {
        parser::Cli::parse()
    }
