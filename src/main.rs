pub mod parser;

fn main() {
    let cli = parser::get_args();
    
    dbg!(&cli);
}