pub mod parser;
pub mod file_read_write;

fn main() {
    #[allow(unused)]
    let cli_args = parser::get_args();
    
    let filename = "toudou.txt";
    let mut tasklist = file_read_write::read_lines(filename);
    
    dbg!(&tasklist);
}