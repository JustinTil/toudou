
pub mod parser;
pub mod file_read_write;

fn main() -> std::io::Result<()>{
    #[allow(unused)]
    let cli_args = parser::get_args();
    
    let filename = "toudou.txt";
    
    let mut tasklist = file_read_write::read_lines(filename);
    
    // If no arguments: print the tasks to the screen
    if cli_args.add_flag.is_none() && cli_args.check_flag.is_none() && cli_args.remove_flag.is_none() {
        let mut index: i8 = 1;
        
        for task in &tasklist {
            println!("{index} - {task}");
            index += 1;
        }
    }
    
    // If requested to add a task
    if cli_args.add_flag.is_some() {
        tasklist.push(cli_args.add_flag.unwrap());
        file_read_write::write_tasklist_to_file(tasklist, filename)?;
    }
    
    Ok(())
}