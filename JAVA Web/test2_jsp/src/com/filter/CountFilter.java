package com.filter;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

@WebFilter(
        urlPatterns = {"/chapter10/page.jsp"},
        initParams = {
                @WebInitParam(name = "count",value = "5000")
        }
)
public class CountFilter implements Filter {

    private int count;

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        String param = filterConfig.getInitParameter("count");
        count = Integer.valueOf(param);
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        count++;
        HttpServletRequest req = (HttpServletRequest) servletRequest;
        ServletContext context = req.getServletContext();
        context.setAttribute("count",count);
        filterChain.doFilter(servletRequest,servletResponse);
    }

    @Override
    public void destroy() {

    }
}
