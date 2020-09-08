module Main where
import AI.HNN.Net
import AI.HNN.Layer
import Data.Array.Vector
import Control.Arrow
import Data.List
import AI.HNN.Neuron
alpha = 0.8 :: Double
epsilon = 0.001 :: Double
layer1, layer2 :: [Neuron]
layer1 = createSigmoidLayer 4 0.5 [0.5, 0.8, 0.4]
layer2 = createSigmoidLayer 1 0.5 [0.5, 0.2, 0.9, 0.3]
net = [layer1,layer2]
finalnet = train alpha epsilon net [([1, 1, 1],[0]),([1, 0, 1],[1]),([1, 1, 0],[1]),([1, 0, 0],[0])]
tr1 = computeNet finalnet [1, 1, 1]
tr0 = computeNet finalnet [1, 0, 1]
td1 = computeNet finalnet [1, 1, 0]
td0 = computeNet finalnet [1, 0, 0]
main = do
     putStrLn $ "results: \n\n" ++ show finalnet
     putStrLn $ "p0: " ++ show tr1
     putStrLn $ "p11: " ++ show tr0
     putStrLn $ "p12: " ++ show td1
     putStrLn $ "p03: " ++ show td0
