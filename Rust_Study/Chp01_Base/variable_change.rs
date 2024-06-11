fn main(){
    //변경 가능한지 굉장히 주의해야함
    //1. mutable : 컴파일러가 변수에 값이 씌어지고 읽혀지는 것을 허용
    //2. immutable : 컴파일러가 변수의 값이 읽히는 것만 허용
    let mut x = 42;
    println!("{}", x);
    x = 13; //mut 가 없으면 여기서 못 바꿈, 에러남
    println!("{}", x);
}