import { BrowserRouter as Router, Routes, Route } from 'react-router-dom'

import Header from './components/layout/Header'
import Footer from './components/layout/Footer'

import Home from './components/pages/Home'

import './index.css'

function App() {
  return (
    <div className="App">
      <Router>
        <Header />
          <Routes>
            <Route path='/' element={<Home />} />
            
          </Routes>
        <Footer />
      </Router>
    </div>
  )
}

export default App
