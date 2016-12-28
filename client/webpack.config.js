module.exports = {
    entry: `${__dirname}/src/app.js`,
    output: {
        path: `${__dirname}/dist`,
        filename: 'bundle.js'
    },
    module: {
        loaders: [
            {
                test: /\.js$/,
                loader: 'babel', 
                query: {
                    presets: ['es2015']
                }
            }
        ]
    }
}