import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;


public class FlipImage {
    public BufferedImage flipVertical(BufferedImage src)
    {
    AffineTransform tx=AffineTransform.getScaleInstance(-1.0,1.0);  //scaling
    tx.translate(-src.getWidth(),0);  //translating
    AffineTransformOp tr=new AffineTransformOp(tx,null);  //transforming
   
    return tr.filter(src, null);  //filtering
    }
    
    public BufferedImage flipHorizontal(BufferedImage src){
    AffineTransform tx=AffineTransform.getScaleInstance(1.0,-1.0);  //scaling
    tx.translate(0,-src.getHeight());  //translating
    AffineTransformOp tr=new AffineTransformOp(tx,null);  //transforming
   
    return tr.filter(src, null);  //filtering
    }
    
    public static void main(String[] args)throws Exception {
    FlipImage obj=new FlipImage();
    BufferedImage src=ImageIO.read(new File("animal.png"));  //reading image
    BufferedImage dest=obj.flipVertical(src);  //flipping vertically
    ImageIO.write(dest,"png",new File("dest_flipVer.png"));
    dest=obj.flipHorizontal(src);  //flipping horizontally
    ImageIO.write(dest,"png",new File("dest_flipHor.png"));
    dest=obj.flipVertical(dest); //flupping both ways
    ImageIO.write(dest,"png",new File("dest_flipBoth.png"));
    }
}