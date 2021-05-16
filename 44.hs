fizzbuzz n = case (rem n 3, rem n 5) of
               (0, 0) -> "fizzbuzz"
               (0, _) -> "fizz"
               (_, 0) -> "buzz"
               (_, _) -> show n
main = mapM_ (putStrLn . fizzbuzz)[1..100]
