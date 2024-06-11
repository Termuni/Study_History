fn main(){
    //x의 자료형을 유추 가능
    let x = 13;
    println!("{}", x);

    //자료형을 명시적으로 지시 가능, 변경 가능
    let x: f64 = 3.14159;
    println!("{}", x);
    
    let x = 13;
    println!("{}", x);

    //선언 후 나중에 초기화 가능(잘 안 씀)
    let z;
    z = 0;
    println!("{}", z);
}