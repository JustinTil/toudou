use std::io::Write;

pub fn read_lines(filename: &str) -> Vec<String> {
    std::fs::read_to_string(filename)
        .unwrap()
        .lines()
        .map(String::from)
        .collect()
}

pub fn write_tasklist_to_file(tasklist: &Vec<String>, filename: &str) -> Result<(), std::io::Error>{
    let mut f  = std::fs::File::create(filename).unwrap();
        
    for task in tasklist {
        f.write(format!("{task}\n").as_bytes())?;
    }
    
    Ok(())
}
