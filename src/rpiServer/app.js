const express = require('express')
const app = express()
const path = require('path')
app.use(express.static(path.join(__dirname,'public')))

app.get('/:appliance',(req,res)=>{
    const { appliance } = req.params;
    res.sendFile(path.join(__dirname, 'public', `${appliance}.html`))
})
app.listen(3000,()=>{console.log("listening on port 3000!")})