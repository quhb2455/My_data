import model as mk
import model2 as mk2


layers = 19
# LRN = True     #working only for layers = 11
conv_1 = True  #working only for layers = 16

m = mk2.make_model(layers, conv_1)

m.summary()


