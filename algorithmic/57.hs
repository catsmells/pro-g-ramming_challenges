import Data.Char
import Text.Printf
crypt f key = map toLetter . zipWith f (cycle key)
  where toLetter = chr . (+) (ord 'A')
enc k c = (ord k + ord c) `mod` 26
dec k c = (ord c - ord k) `mod` 26
encrypt = crypt enc
decrypt = crypt dec
convert = map toUpper . filter isLetter
main = do
  let key  = "GITHUB"
      text = "poop lube " ++ "anime bones"
      encr = encrypt key $ convert text
      decr = decrypt key encr
  printf "    input: %s\n      key: %s\nencrypt: %s\ndecrypt: %s\n"
    text key encr decr
