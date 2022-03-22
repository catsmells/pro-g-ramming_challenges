module Cliwav.Main.Drcat
  where
import UI.Command
import qualified Synthesizer.Plain.Oscillator as Osci
import qualified Synthesizer.Basic.Wave as Wave
import Data.List
import Data.Char
import NumericPrelude.Numeric
import Prelude ()
import System.Exit (ExitCode, )
import NumericPrelude.Base
import qualified Synthesizer.Plain.Play as Play
wavcli = def {
	appName = "Pro/g/ramming Challenges: Sound Synthesizer",
	appCategories = ["Challenges", "Sound", "Audio/Visual"],
	appCmds = [sine, sawtooth, square]
}
sq = def {
	cmdName = "square",
	cmdHandler = squareHandler
}
sw = def {
	cmdName = "sawtooth",
	cmdHandler = sawtoothHandler
}
sn = def {
	cmdName = "sine",
	cmdHandler = sineHandler
}
squareHandler = liftIO $ square =
                                play (Osci.static (Wave.distort (^6) Wave.saw) 0 (0.01::Double))
sawtoothHandler = liftIO $ saw =
			        play (Osci.static (Wave.triangleAsymmetric 0.3) 0 (0.04::Double))
sineHandler = liftIO $ sine =
                                Play.monoToInt16 (44100::Double) (map sin [0::Double,0.1..])
main :: IO ()
main = wavcli $ do
       wavcli
