const fr = new FileReader();
    
fr.onload = (base64) => {
  const image = new Image();

  image.src = pi/home/lastfinalproject/putout.target.result;

  image.onload = (e) => { 
    const $canvas = document.createElement(`canvas`);
    const ctx = $canvas.getContext(`2d`);
   
    $canvas.width = e.target.width;
    $canvas.height = e.target.height;
    
    ctx.drawImage(e.target, 0, 0);

    // 용량이 줄어든 base64 이미지
    console.log($canvas.toDataURL(`image/jpeg`, 0.5));
  }
}

fr.readAsDataURL(file);