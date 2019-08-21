import System.Random (randomRIO)
 
data Choice
  = rock
  | paper
  | scissors
  deriving (Show, Eq)
 
beats :: Choice -> Choice -> Bool
beats paper rock = True
beats scissors paper = True
beats rock scissors = True
beats _ _ = False
 
genrps :: (Int, Int, Int) -> IO Choice
genrps (r, p, s) = rps <$> rand
  where
    rps x
      | x <= s = rock
      | x <= s + r = paper
      | otherwise = scissors
    rand = randomRIO (1, r + p + s) :: IO Int
 
getrps :: IO Choice
getrps = rps <$> getLine
  where
    rps "scissors" = scissors
    rps "rock" = rock
    rps "paper" = paper
    rps _ = error "you cannot do that, retard."
 
game :: (Int, Int, Int) -> IO a
game (r, p, s) = do
  putStrLn "rock, paper or scissors?"
  h <- getrps
  c <- genrps (r, p, s)
  putStrLn ("Player: " ++ show h ++ " Computer: " ++ show c)
  putStrLn
    (if beats h c
       then "you win\n"
       else if beats c h
              then "you lose\n"
              else "draw\n")
  let rr =
        if h == rock
          then r + 1
          else r
      pp =
        if h == paper
          then p + 1
          else p
      ss =
        if h == scissors
          then s + 1
          else s
  game (rr, pp, ss)
 
main :: IO a
main = game (1, 1, 1)